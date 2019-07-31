//
// Created by Eason on 2019/7/30.
//
#include<iostream>
#include <vector>
#include "stack"

using namespace std;

namespace stackk{
    class IsPopOrder{
    public:
        static bool isPopOrder(vector<int> &pushV,vector<int> &popV) {
            if(pushV.empty()) {
                return false;
            }

            stack<int> temp;
            int j = 0;

            for(int i = 0; i < pushV.size(); i++) {
                temp.push(pushV[i]);
                while(temp.top() == popV[j] && j < popV.size()) {
                    j++;
                    temp.pop();
                }
            }

            return temp.empty();
        }
    };
}

