#include<iostream>
#include <vector>
#include "dp/maxProfit.cpp"

using namespace dp;

int main()
{
    // std::string s = "aacecaaa";
    std::vector<int> v{7,6,4,3,1};

    std::cout<<maxProfit::getMaxProfit(v);

    return 0;
}



