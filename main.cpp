#include<iostream>
#include <vector>
#include "map"
#include "algorithm"
#include "./dp/coinsCash.cpp"

using namespace std;

int main()
{
    vector<int> vec = {3,5};
    cout<<dp::coinsCash::coinsChange(vec, 4)<<endl;
}



