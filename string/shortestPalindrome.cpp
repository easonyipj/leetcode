//
// Created by 易平建 on 2019-06-29.
// https://leetcode-cn.com/problems/shortest-palindrome/
#include "string"
using namespace std;


namespace str{
    class shortestPalindrome{
    public:
        static string getShortestPalindrome(string s) {
            if(s.empty()) {
                return "";
            }

            if(s.length() == 1) {
                return s;
            }

            int right;

            for(int i = s.length() - 1; i >= 0; i--) {
                if(check(s, 0, i)) {
                    right = i;
                    break;
                }
            }

            string ans = "";

            for(int i = s.length() - 1; i > right; i--) {
                ans += s[i];
            }

            ans += s;

            return s;

        }

        static bool check(string s, int low, int high) {
            if(low == high) {
                return true;
            }

            while(low < high) {
                if(s[low]!=s[high])
                    return false;
                low++;
                high--;
            }

            return true;
        }
    };
}

