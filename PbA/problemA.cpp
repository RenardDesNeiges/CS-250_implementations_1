// Implementation for problem A "Santa's Knapsack"

#include <iostream>
#include <string>
#include<vector>
#include<set>

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

//bad implementation (not dynamic programming)
long knapsacRec(std::vector<int> w,std::vector<int> h, std::vector<int> c, std::set<int> k, int m, int n){
    if(n <= 0){
        return 0;
    }
    if (w.at(n-1)>m || k.find(c.at(n-1)) != k.end() )
    {
        return knapsacRec(w,h,c,k,m,n-1);
    }
    else{
        std::set<int> nK = k;
        nK.insert((int) c.at(n-1));
        long take = h.at(n-1) + knapsacRec(w,h,c,nK,m-w.at(n-1),n-1);
        long leave = knapsacRec(w,h,c,k,m,n-1);
        if(take>=leave){
            return take;
        }
        else
        {
            return leave;
        }
        
    }
}

int main() {
    // getting the inputs from the input buffer

    //getting the parameters from the first line
    std::string line;
    std::getline(std::cin, line);
    std::vector<long> splitLine = splitStringByChar(line,' ');
    int n = splitLine.at(0);
    int m = splitLine.at(1);
    int k = splitLine.at(2);

    //getting the values from the k following lines
    std::vector<int> w;
    std::vector<int> h;
    std::vector<int> c;

    for(int i = 0; i<k; i++){
        std::getline(std::cin, line);   
        splitLine = splitStringByChar(line,' ');
        
        for(int j = 0; j<splitLine.at(0);j++){
            w.push_back(splitLine.at(1+2*j));
            h.push_back(splitLine.at(2+2*j));
            c.push_back(i);
        }
    }   
  
    std::set<int> kV;
    std::cout << knapsacRec(w,h,c,kV,m,n) << std::endl;
    return EXIT_SUCCESS;
}