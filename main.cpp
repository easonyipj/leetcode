#include<iostream>
#include <vector>
#include "map"
#include "algorithm"
#include "./sort/selectSort.cpp"

using namespace std;

int main()
{
    vector<int> nums = {4,5,3,6,2,5,1};

    nums = sort::selectSort::sort(nums);

    for(int i : nums) {
        cout<< i <<endl;
    }
}



