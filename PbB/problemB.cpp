// Implementation for problem A "Santa's Knapsack"

#include <iostream>
#include <string>
#include<vector>

std::vector<int> splitStringByChar(std::string str, char split)
{
    std::string nb = "";
    std::vector<int> out;

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

int main() {
    // getting the inputs from the input buffer

    //getting the parameters from the first line
    std::string line;
    std::getline(std::cin, line);
    std::vector<int> splitLine = splitStringByChar(line,' ');
    int n = splitLine.at(0);

    std::cout << n << std::endl;

    return EXIT_SUCCESS;
}