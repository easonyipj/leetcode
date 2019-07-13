//
// Created by Eason on 2019/7/12.
// 单词拆分系列
#include "string"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

namespace dp{
    class wordBreak{
    public:
        // 1 https://leetcode-cn.com/problems/word-break/
        static bool getWordBreakI(const string &s, vector<string>& wordDict) {

            return wordbreak(s, wordDict, 0);
        }

        // 暴力递归
        static bool wordbreak(const string &s, vector<string>& wordDict, int index) {
            if(index == s.size()) {
                return true;
            }

            for(int len = 1; index + len <= s.size(); len++) {
                string sub = s.substr(index, len);
                if(std::find(wordDict.begin(), wordDict.end(), sub) != wordDict.end() && wordbreak(s, wordDict, index + len)) {
                    return true;
                }
            }

            return false;
        }

        // 动态规划
        static bool wordBreakDp(const string &s, vector<string>& wordDict){
            if(s.empty()) {
                return true;
            }

            int n = s.size();
            int dp[n + 1];
            dp[0] = 1;

            for(int i = 1; i <= n; i++) {
                for(int j = 0; j < i; j++) {
                    if(dp[j] == 1 && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                        dp[i] = 1;
                        break;
                    }
                }
            }

            return dp[n] == 1;

        };

        // 2 https://leetcode-cn.com/problems/word-break-ii/
        static vector<string> getWordBreakII(string& s, vector<string>& wordDict) {
            vector<string> ans;

            if(s.empty()) {
                ans.emplace_back("");
                return ans;
            }

            return back(s, wordDict, 0);

        }

        // 暴力回溯
        static vector<string> back(string& s, vector<string>& wordDict, int index) {
            vector<string> res;
            if(index == s.size()) {
                res.emplace_back("");
                return res;
            }

            for(int len = 1; len <= s.size() - index; len++) {
                if(find(wordDict.begin(), wordDict.end(), s.substr(index, len)) != wordDict.end()) {
                    vector<string> tempRes = back(s, wordDict, index + len);
                    for(int i = 0; i < tempRes.size(); i++) {
                        res.emplace_back(s.substr(index, len) + (tempRes[i] == "" ? "" : " ") + tempRes[i]);
                    }
                }
            }

            return res;
        }

        // 记忆回溯
        static map<int, vector<string>> kmap;
        static vector<string> mback(string& s, vector<string>& wordDict, int index) {
            if(kmap.count(index)) {
                return kmap[index];
            }
            vector<string> res;
            if(index == s.size()) {
                res.emplace_back("");
                return res;
            }

            for(int len = 1; len <= s.size() - index; len++) {
                if(find(wordDict.begin(), wordDict.end(), s.substr(index, len)) != wordDict.end()) {
                    vector<string> tempRes = mback(s, wordDict, index + len);
                    for(int i = 0; i < tempRes.size(); i++) {
                        res.emplace_back(s.substr(index, len) + (tempRes[i] == "" ? "" : " ") + tempRes[i]);
                    }
                }
            }

            kmap[index] = res;
            return res;
        }

        // 动态规划
        static vector<string> dp(string& s, vector<string>& wordDict) {
            vector<vector<string>> res(s.size() + 1);

            res[0] = {""};

            for(int len = 1; len <= s.size(); len++) {
                vector<string> str;
                int j = 0;
                for(; j < len; j++) {
                    if(res[j].size() > 0 && find(wordDict.begin(), wordDict.end(), s.substr(j, len - j)) != wordDict.end()) {
                        for(int i = 0; i < res[j].size(); i++) {
                            str.emplace_back(res[j][i] + (res[j][i] == "" ? "" : " ") + s.substr(j, len - j));
                        }
                    }
                }

                res[len] = str;

            }

            return res[s.size()];
        }


    };
}

