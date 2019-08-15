//
// Created by Eason on 2019/8/15.
// 青蛙跳跃 https://leetcode-cn.com/problems/jump-game/
// 题解 https://www.cnblogs.com/yuzhangcmu/p/4039840.html
// 第三课 p41

#include<cmath>
#include "limits.h"
#include<iostream>
#include "vector"

using namespace std;

namespace dp{
    class canJump{
    public:
        // 动态规划I leetcode超时
        static bool canJumpDp(vector<int>& nums) {
            vector<bool>  dp(nums.size());
            dp[0] = true;
            for(int i = 1; i < nums.size(); i++) {
                dp[i] = false;
                for(int j = 0; j < i; j++) {
                    if(dp[j] && nums[j] >= i - j) {
                        dp[i] = true;
                        break;
                    }
                }
            }

            return dp[nums.size() - 1];
        }

        // 动态规划II leetcode超时
        static bool canJumpDpII(vector<int>& nums) {
            bool can;
            for(int i = 1; i < nums.size(); i++) {
                can = false;
                for(int j = 0; j < i; j++) {
                    if(nums[j] >= i - j) {
                        can = true;
                        break;
                    }
                }
                if(!can) {
                    return false;
                }
            }

            return true;
        }

        // 贪心算法
        static bool canJumpGreed(vector<int>& nums){
            vector<int> maxIndexs(nums.size());
            for(int i = 0; i < nums.size(); i++) {
                maxIndexs[i] = i + nums[i];
            }

            int index = 0;
            int maxIndex = maxIndexs[0];

            while(index < nums.size() && index <= maxIndex) {
                if(maxIndexs[index] > maxIndex) {
                    maxIndex = maxIndexs[index];
                }
                index++;
            }

            return index == nums.size();
        }
    };
}
