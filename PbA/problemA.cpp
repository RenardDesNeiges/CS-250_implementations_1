    // Implementation for problem A "Santa's Knapsack"

    #include <iostream>
    #include <string>
    #include<vector>

    std::vector<long> splitStringByChar(std::string str, char split)
    {
        std::string nb = "";
        std::vector<long> out;

        for (auto x : str) 
        {
            if (x == split)
            {
                out.push_back(std::stol(nb));
                nb = "";
            }
            else {
                nb = nb + x;
            }
        }
        out.push_back(std::stol(nb));
        return out;
    }

    std::int64_t knapsack(std::int64_t max[],std::int64_t maxM,std::int64_t w[],std::int64_t h[],std::int64_t c[],std::int64_t i[], std::int64_t m, std::int64_t n,std::int64_t maxN){
        
        if(n<0){
            return 0;
        }
        else if(w[n]>m){
            if(n<1){
                return 0;
            }
            if(max[(n-1)*maxM+m] == -1){
                max[(n-1)*maxM+m] = knapsack(max,maxM,w,h,c,i,m,n-1,maxN);
            }
            return max[(n-1)*maxM+m];
        }
        else{

            std::int64_t take = 0;

            if(c[n]-1 < 0){
                take = h[n];
            }
            else{
                std::int64_t nm = m-w[n];
                std::int64_t nn = i[c[n]-1];

                if(max[nn*maxM+nm] == -1){
                    max[nn*maxM+nm] = knapsack(max,maxM,w,h,c,i,nm,nn,maxN);   
                }
                take = h[n] + max[nn*maxM+nm];
            }

            
            
            std::int64_t leave;
            if(n < 1){
                leave = 0;
            }
            else{
                if(max[(n-1)*maxM+m] == -1){
                    max[(n-1)*maxM+m] = knapsack(max,maxM,w,h,c,i,m,n-1,maxN);
                }
                leave = max[(n-1)*maxM+m];
            }
            if(leave > take){
                return leave;
            }
            else
            {
                return take;
            }
            
        }
        
    }

    int main() {
        // getting the inputs from the input buffer

        //getting the parameters from the first line
        std::string line;
        std::getline(std::cin, line);
        std::vector<long> splitLine = splitStringByChar(line,' ');
        std::int64_t n = splitLine.at(0);
        std::int64_t m = splitLine.at(1);
        std::int64_t k = splitLine.at(2);

        //getting the values from the k following lines
        std::int64_t* w = new std::int64_t[n+1];
        std::int64_t* h = new std::int64_t[n+1];
        std::int64_t* c = new std::int64_t[n+1];
        std::int64_t* indices = new std::int64_t[k+1];

        std::int64_t accInd = 0;
        std::int64_t acc = 0;
        
        for(std::int64_t i = 0; i<k; i++){
            std::getline(std::cin, line);   
            splitLine = splitStringByChar(line,' ');
            accInd += splitLine.at(0);
            indices[i]=accInd-1;
            for(std::int64_t j = 0; j<splitLine.at(0);j++){
                w[acc] = splitLine.at(1+2*j);
                h[acc] = splitLine.at(2+2*j);
                c[acc] = i;
                acc += 1;
            }
        }


        int maxKey = (n+1)*(m+1);
        std::int64_t*  maxVal = new std::int64_t[(n+1)*(m+1)];
        for(std::int64_t i = 0; i<n+1; i++){
            for(std::int64_t j = 0; j<m+1;j++){
                maxVal[i*(m+1)+j] = -1;
            }
        }

        std::cout << knapsack(maxVal,m,w,h,c,indices,m,n-1,n) << std::endl;

        return EXIT_SUCCESS;
    }