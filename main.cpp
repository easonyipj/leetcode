#include<iostream>
#include <vector>
#include "dp/maxProfit.cpp"

using namespace dp;

int main()
{
    // std::string s = "aacecaaa";
    std::vector<int> v{1,2,3,4,5};

    std::cout<<maxProfit::getMaxProfitIII(v);

    return 0;
}



