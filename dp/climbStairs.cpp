//
// Created by 易平建 on 2019-06-29.
// 爬楼梯 https://leetcode-cn.com/problems/climbing-stairs/

namespace dp{
    class climbStairs{
    public:
        static int getClimbStairs(int n) {
            if(n <= 3) {
                return n;
            }

            // count[n]数组保存爬到n层楼梯的爬法
            // 由于每次只能爬一层或者两层 所以每一层要么从其下一层爬上来 要么从其下两层爬上来
            // count[n] = count[n - 1] + count[n - 2]

            int count[n + 1];
            count[0] = 1;
            count[1] = 1;

            for(int i = 2; i <= n; i++) {
                count[i] = count[i - 1] + count[i - 2];
            }

            return count[n];
        }
    };
}

