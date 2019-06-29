//
// Created by 易平建 on 2019-06-29.
// 最大子序列和 https://leetcode-cn.com/problems/maximum-subarray/

#include "vector"

namespace dp{
    class maxSubArray{
    public:
        // 动态规划
        static int getMaxSubArray(std::vector<int>& nums) {
            if(nums.empty()) {
                return 0;
            }

            // sum 为最大连续子序列和
            // n 为当前连续子序列和
            int sum = nums[0];
            int n = nums[0];

            // 当 n 小于 0 时，连续子序列和必然减小，所以n
            for(int i = 1; i < nums.size(); i++) {

                // 如果当前连续子序列和小于0，则舍弃当前连续子序列，从i开始重新计算
                if(n < 0) {
                    n = nums[i];
                }else {
                    n += nums[i];
                }

                // 比较当前连续子序列和与最大连续子序列和
                if(n > sum) {
                    sum = n;
                }
            }

            return sum;

        }

    };
}

