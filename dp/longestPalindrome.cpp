//
// Created by 易平建 on 2019-06-28.
// 最长回文字串 https://leetcode-cn.com/problems/longest-palindromic-substring/comments/
#include "string"
#include <vector>

using namespace std;

namespace dp{
    class longestPalindrome{
    public:
        static string getLongestPalindrome(string s) {
            if(s.empty()) {
                return "";
            }

            int n = s.length();

            if(n == 1) {
                return s;
            }

            // c[i][j] = 1 表示[i,j]之间的字串是回文
            std::vector<std::vector<int>> c(n, std::vector<int>(n));
            for(int i = 0; i < n; i++) {
                c[i][i] = 1;
            }

            int start = 0;
            int length = 1;

            // len 表示待判断字串长度
            for(int len = 2; len <= n; len++) {
                for(int i = 0; i <= n - len; i++) {
                    int j = i + len -1;

                    // 字串长度为2时，只要i j两个元素相等，则字串为回文
                    // 字串长度不为2时，i j元素相等且[i + 1,j - 1]为回文，则该字串为回文
                    if((j - i == 1 && s[i] == s[j]) || (s[i] == s[j] && c[i + 1][j - 1] == 1)) {
                        c[i][j] = 1;
                        start = i;
                        length = len;
                    }
                }
            }

            return s.substr(start, length);

        }
    };
}






