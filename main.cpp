#include<iostream>
#include <vector>
#include "map"
#include "algorithm"
#include "./dp/bombEnemy.cpp"

using namespace std;

int main()
{
    string s = "sssaaabcd";

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

    cout<<s<<endl;

}



