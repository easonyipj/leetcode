#include<iostream>
#include <vector>
#include "map"
#include "algorithm"
#include "./dp/uniquePaths.cpp"

using namespace std;

int main()
{
    vector<vector<int>> vec = {
                               {0, 0, 0},
                               {0, 1, 0},
                               {0, 0, 0}
                              };
    cout<<dp::uniquePaths::getUniquePathsII(vec)<<endl;
}



