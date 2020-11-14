// Implementation for problem A "Santa's Knapsack"

#include <iostream>
#include <string>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

vector<int> splitStringByChar(string str, char split)
{
    string nb = "";
    vector<int> out;

    for (auto x : str) 
    {
        if (x == split)
        {
            out.push_back(stol(nb));
            nb = "";
        }
        else {
            nb = nb + x;
        }
    }
    out.push_back(stol(nb));
    return out;
}

bool compTpl(tuple<int,int> i, tuple<int,int> j){
    return get<1>(i) > get<1>(j);
}

tuple<int,vector<tuple<int,int>>> mergeAndCount(vector<tuple<int,int>> a,vector<tuple<int,int>> b){
    vector<tuple<int,int>> c;
    int cnt = 0;
    while(a.size() > 0 && b.size() > 0){
        if(b.at(0)>a.at(0)){
            c.push_back(b.at(0));
            cnt += a.size();
            b.erase(b.begin());
        }
        else{
            c.push_back(a.at(0));
            a.erase(a.begin());
        }
    }
    if(a.size()<=0){
        for(auto e : a){cout << get<0>(e) << ";" << get<1>(e) << " ";} cout << endl;
        for(auto e : c){cout << get<0>(e) << ";" << get<1>(e) << " ";} cout << endl;
        c.insert(c.end(),b.begin(),b.end());
        for(auto e : c){cout << get<0>(e) << ";" << get<1>(e) << " ";} cout << endl;
    }
    else{
        c.insert(c.end(),b.begin(),b.end());
    }
    return make_tuple(cnt,c);
}

tuple<int,vector<tuple<int,int>>> sortAndCount(vector<tuple<int,int>> l){
    if(l.size() <= 1){
        return make_tuple(0,l);
    }
    else{
        std::vector<tuple<int,int>> a(l.begin(), l.begin() + l.size() / 2);
        std::vector<tuple<int,int>> b(l.begin() + (l.size() / 2)+1, l.end());
        tuple<int,vector<tuple<int,int>>> ra = sortAndCount(a);
        tuple<int,vector<tuple<int,int>>> rb = sortAndCount(b);
        tuple<int,vector<tuple<int,int>>> r = mergeAndCount(a,b);
        return make_tuple(get<0>(ra)+get<0>(rb)+get<0>(r),l);
    }

}

int main() {
    // getting the inputs from the input buffer

    //getting the parameters from the first line
    string line;
    getline(cin, line);
    vector<int> splitLine = splitStringByChar(line,' ');
    int n = splitLine.at(0);
    getline(cin, line);
    vector<int> a = splitStringByChar(line,' ');
    getline(cin, line);
    vector<int> b = splitStringByChar(line,' ');

    vector<tuple<int,int>> el;
    for(int i = 0; i<n;i++){el.push_back(make_tuple(a.at(i),b.at(i)) );}
    sort(el.begin(),el.end(),compTpl);

    // cout << n << endl;
    // for(auto e : el){cout << get<0>(e) << ";" << get<1>(e) << " ";} cout << endl;
    
    cout << get<0>(sortAndCount(el)) << endl;

    return EXIT_SUCCESS;
}