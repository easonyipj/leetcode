//
// Created by Eason on 2019/8/17.
// find spell error https://www.nowcoder.com/practice/42852fd7045c442192fa89404ab42e92
// 题目
//1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
//2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello
//3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC

#include<iostream>
#include "string"
#include "vector"

using namespace std;

namespace str{
    class spellError{
    public:
        static void findSpellError(vector<string> & ss, int n) {
           if(n <= 0) {
               cout<<endl;
           }

           for(int k = 0; k < ss.size(); k++) {
               string s = ss[k];
               if(s.length() < 3) {
                   cout<<s<<endl;
                   continue;
               }
               // 1 aaa
               for(int i = 1, pre = 0, next = 2; next < s.size();) {
                   if(s[i] == s[pre] && s[i] == s[next]) {
                       // 删掉next处字符
                       s.erase(s.begin() + next);
                       continue;
                   }else{
                       pre++;
                       i++;
                       next++;
                   }
               }

               // 2 aabb
               for(int i = 1, pre = 0; i < s.size() - 2; ) {
                    if(s[pre] == s[i]) {
                        if(s[pre + 2] == s[i + 2]) {
                            // 删掉第二对第一处字符
                            s.erase(s.begin() + pre + 2);
                            continue;
                        }
                    }
                    i++;
                    pre++;
               }

               cout<<s<<endl;

           }

        }
    };
}