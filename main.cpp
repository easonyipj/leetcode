#include<iostream>
#include <vector>
#include "dp/wordBreak.cpp"

using namespace dp;

int main()
{
    std::string s = "catsanddog";
    std::vector<int> v{1,2,3,4,5};
    std::vector<string> list{"cat", "cats", "and", "sand", "dog"};

    vector<string> res = wordBreak::dp(s, list);
    for(int i = 0; i < res.size(); i++) {
        std::cout<<res[i]<<endl;
    }

    return 0;
}



