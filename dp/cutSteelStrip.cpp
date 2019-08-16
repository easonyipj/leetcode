//
// Created by 易平建 on 2019-06-26.
// https://www.cnblogs.com/mengwang024/p/4342796.html 切钢条

#include "algorithm"

using namespace std;

namespace dp{
    class cutSteelStrip{
    public:
        // 自顶向下递归
        static int cut(int *p, int n) {
            if(n == 0) {
                return 0;
            }

            int q = -1;
            for(int i = 1; i <= n; i++) {
                q = max(q, p[i] + cut(p, n - i));
            }

            return q;
        }

        // 动态规划1: 带备忘录的自顶向下方法
        static int cutWithMemo(int *p, int n, int *r) {
            if(r[n] > 0) {
                return r[n];
            }

            if(n == 0) {
                r[n] = 0;
                return 0;
            }

            int q = -1;
            for(int i = 1; i <= n; i++) {
                q = max(q, p[i] + cutWithMemo(p, n - i, r));
            }

            r[n] = q;
            return q;
        }

        // 动态规划2: 自底向上法
        static int bottomToTop(int *p, int n) {

            int *r = new int[n + 1];
            r[0] = 0;

            if(n <= 1) {
                return p[n];
            }

            int q = -1;

            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= i; j++) {
                    q = max(q, p[j] + r[i - j]);
                }
                r[i] = q;
            }

            return q;
        }


    };
}

