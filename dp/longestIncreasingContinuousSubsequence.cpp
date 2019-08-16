//
// Created by Eason on 2019/8/16.
// Longest Continuous Increasing Subsequence

#include<cmath>
#include "limits.h"
#include<iostream>
#include "vector"
#include "algorithm"

using namespace std;

namespace dp{
    class longestIncreasingContinuousSubsequence{
    public:
        static int findLengthOfLCIS(vector<int>& nums) {
            if(nums.empty()) {
                return 0;
            }

            int leftToRight = -1;
            vector<int> dpLeft(nums.size());

            for(int i = 0; i < nums.size(); i++) {
                dpLeft[i] = 1;
                if(i > 0 && nums[i - 1] < nums[i]) {
                    dpLeft[i] = dpLeft[i - 1] + 1;
                }

                leftToRight = max(dpLeft[i], leftToRight);
            }

            reverse(nums.begin(), nums.end());

            int rightToLeft = -1;
            vector<int> dpRight(nums.size());

            for(int i = 0; i < nums.size(); i++) {
                dpRight[i] = 1;
                if(i > 0 && nums[i - 1] < nums[i]) {
                    dpRight[i] = dpRight[i - 1] + 1;
                }

                rightToLeft = max(dpRight[i], rightToLeft);
            }

            return max(rightToLeft, leftToRight);

        }
    };
}
