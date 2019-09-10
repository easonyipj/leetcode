//
// Created by Eason on 2019/9/10.
//
/**
 * Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ),
 the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "string"
#include "stack"
#include "vector"

using namespace std;

class BasicCalculator{
public:
    static bool compareOptPriority(char &A, char &B) {
        int priorityA = 0;
        int priorityB = 0;
        //特此注意,认为'(',优先级最低
        if (B == '(') return true;
        if (A == '+' || A == '-') {
            priorityA = 0;
        } else {
            priorityA = 1;
        }

        if (B == '+' || B == '-') {
            priorityB = 0;
        } else {
            priorityB = 1;
        }

        return priorityA > priorityB;
    }
    static void getPostExpression(string &s, vector<char> &post) {
        int i = 0;
        stack<char> opt;
        while (i<s.size()) {
            if (s[i] == ' ') {
                //忽略空格
                i++;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                //碰到数字直接输出，一直到非数字
                while (s[i] >= '0' && s[i] <= '9') {
                    post.push_back(s[i]);
                    i++;
                }
                post.push_back(' ');
            } else {
                //先处理弹符号栈场景，后处理压符号栈场景
                if (s[i] == ')') {
                    //碰到')'，弹出符号栈到碰到'(',弹出'('；
                    while (opt.top() != '(') {
                        post.push_back(opt.top());
                        opt.pop();
                    }
                    opt.pop();
                } else if(!opt.empty() && !compareOptPriority(s[i], opt.top())) {
                    //符号栈 栈顶符号优先级较高，则弹出直到低于当前符号，并把当前符号压栈
                    while (!opt.empty() && !compareOptPriority(s[i], opt.top())){
                        post.push_back(opt.top());
                        opt.pop();
                    }
                    opt.push(s[i]);
                } else {
                    //剩余情况直接压栈，如高优先级符号，栈顶为'(',符号栈为空
                    opt.push(s[i]);
                }
                i++;
            }
        }
        while (!opt.empty()) {
            post.push_back(opt.top());
            opt.pop();
        }
    }
    static int calPostExpression(vector<char> &post) {
        stack<long> res;
        long num = 0;
        for (int i=0;i<post.size();i++) {
            if (post[i] == ' ') {
                continue;
            }

            if (post[i] >= '0' && post[i] <= '9') {
                //碰到数字，计算并压栈
                while (i < post.size() && post[i] >= '0' && post[i] <= '9') {
                    num = num*10 + post[i] - '0';
                    i++;
                }
                i--;
                res.push(num);
                num = 0;
            } else {
                //符号则取栈顶两个数计算并弹出，结果压栈
                long B = res.top();
                res.pop();
                long A = res.top();
                res.pop();
                long tmp;
                if (post[i] == '+') {
                    tmp = A + B;
                } else if (post[i] == '-') {
                    tmp = A - B;
                } else if (post[i] == '*') {
                    tmp = A * B;
                } else if (post[i] == '/') {
                    tmp = A / B;
                }
                res.push(tmp);
            }
        }
        return (int)res.top();
    }

    static int calculate(string s) {
        vector<char> post;
        getPostExpression(s, post);

        return calPostExpression(post);
    }

};

