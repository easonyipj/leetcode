//
// Created by 易平建 on 2019-06-29.
// 最大子序列和 https://leetcode-cn.com/problems/maximum-subarray/
// 题解 https://leetcode-cn.com/problems/maximum-subarray/solution/xiang-xi-jie-du-dong-tai-gui-hua-de-shi-xian-yi-li/

#include "vector"

using namespace std;

namespace dp{
    class maxSubArray{
    public:
        // 易懂版动态规划
        static int getMaxSubArrayDp(std::vector<int>& nums) {
            if(nums.empty()) {
                return 0;
            }

            // 在每一个扫描点计算以该点数值为结束点的子数列的最大和（正数和）。
            int max_ending_here = nums[0];
            int max_so_far = nums[0];

            for (int i = 1; i < nums.size(); i ++ ) {
                // 以每个位置为终点的最大子数列 都是基于其前一位置的最大子数列计算得出,
                max_ending_here = max(nums[i], max_ending_here + nums[i]);
                max_so_far = max(max_so_far, max_ending_here);
            };

            return max_so_far;

        }

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

