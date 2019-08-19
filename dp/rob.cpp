//
// Created by 易平建 on 2019-06-29.
// 打家劫舍
// 打家劫舍II https://leetcode-cn.com/problems/house-robber-ii/
#include "vector"

using namespace std;

namespace dp{
    class rob{
    public:
        static int dpRob(std::vector<int>& nums) {
            if(nums.empty()) {
                return 0;
            }

            int n = nums.size();

            if(n == 1) {
                return nums[0];
            }

            if(n == 2) {
                return max(nums[0], nums[1]);
            }

            // sum[n]表示打劫到第n家时的最大金额
            int sum[n];
            sum[0] = nums[0];
            sum[1] = max(nums[0], nums[1]);

            // 由于不能打劫相邻的家庭 所以当i >= 2时 需要比较打劫当前家庭的金额+打劫到前两个家庭的最大金额 与 打劫到前一个家庭的最大金额
            // sum[i] = max(sum[i - 2] + nums[i], sum[i - 1])
            for(int i = 2; i < n; i++) {
                sum[i] = max(sum[i - 2] + nums[i], sum[i - 1]);
            }

            return sum[n - 1];

        }
    };
}

