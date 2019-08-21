//
// Created by Eason on 2019/8/20.
//
#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

namespace exam{
    class huawei{
    public:
        static void postTranslate() {
//            string s;
//            getline(cin, s);
//
//            vector<string> in;
//
//            int i = 0;
//            while(i < s.size() && s[i] != '\0') {
//                string s1;
//                while(i < s.size() && s[i] != ' ') {
//                    s+=s[i];
//                    i++;
//                }
//                i++;
//                in.push_back(s1);
//            }
//
//            vector<string> out;
//            out.push_back("");
//            for(int j = 1; j < in.size(); j++) {
//                if(in[j] == "A") {
//                    out.push_back("12");
//                    out.push_back("34");
//                }else if(in[j] == "B") {
//                    out.push_back("AB");
//                    out.push_back("CD");
//                }else{
//                    out.push_back(in[j]);
//                }
//            }
//
//            out[0] = to_string(out.size());
//
//            for(string ss : out) {
//                cout << ss << " ";
//            }

                int n;
                cin >> n;
                vector<string> out;


                while(--n) {
                    int k;
                    cin >> k;
                    if(k == 'A') {
                        out.push_back("12");
                        out.push_back("34");
                        n++;
                    }else if(k == 'B') {
                        out.push_back("AB");
                        out.push_back("CD");
                        n++;
                    }else {
                        out.push_back(to_string(k));
                    }
                }

                cout << n << " ";
                for(string s : out) {
                    cout<< s << " ";
                }
        }

        static void findMin() {
            int low;
            int high;
            cin >> low >>high;

            vector<int> nums;

            for(int i = low; i < high; i++) {
                // 判断i是否为质数
                int flag = 1;
                int k = i - 1;
                while (k > 1) {
                    int mod = i % k;
                    if(mod == 0) {
                        flag = 0;
                        break;
                    }
                    k--;
                }

                if(flag == 1) {
                    nums.push_back(i);
                }
            }

            int k1 = 0;
            int k2 = 0;
            for(int n : nums) {
                if(n < 10) {
                    k1 += n;
                }else if(n >= 10){
                    k1 += n % 10;
                    k2 += (n / 10) % 10;
                }
            }

            cout << min(k1, k2);
        }

        static void sendMessage() {

            string sender;
            cin >> sender;

            int n;
            cin >> n;

            vector<vector<string>> groups;
            map<string, int> state;

            while(n--) {
                string s;
                getline(cin ,s);
                vector<string> group;

                int i = 0;
                while(i < s.size() && s[i] != '\0') {
                    string s1;
                    while(i < s.size() && s[i] != ',') {
                        s+=s[i];
                        i++;
                    }
                    i++;
                    state["s1"] = 0;
                    group.push_back(s1);
                }

                groups.push_back(group);
            }

            state[sender] = 1;
            vector<int> groupState(n, 0);

            // 先找到发信人所在的群组
            for(int i = 0; i < n; i++) {
                if(find(groups[i].begin(), groups[i].end(), sender) != groups[i].end()) {
                    // 标记每个人
                    for(string &name : groups[i]) {
                        state[name] = 1;
                    }
                    groupState[i] = 1;
                }
            }

            // 查看未被标记的群组
            auto it = state.begin();
            while(it != state.end() && it -> second == 1) {
                for(int i = 0; i < n; i++) {
                    if(groupState[i] == 1) {
                        continue;
                    }
                    if(find(groups[i].begin(), groups[i].end(), it -> first) != groups[i].end()) {
                        // 标记每个人
                        for(string &name : groups[i]) {
                            state[name] = 1;
                        }
                        groupState[i] = 1;
                    }
                }
                it++;
            }

            // 查看未被标记的群组
            it = state.begin();
            while(it != state.end() && it -> second == 1) {
                for(int i = 0; i < n; i++) {
                    if(groupState[i] == 1) {
                        continue;
                    }
                    if(find(groups[i].begin(), groups[i].end(), it -> first) != groups[i].end()) {
                        // 标记每个人
                        for(string &name : groups[i]) {
                            state[name] = 1;
                        }
                        groupState[i] = 1;
                    }
                }
                it++;
            }

            it = state.begin();
            int num = 0;
            while(it != state.end() && it -> second == 1) {
                num++;
            }
            cout << num;
        }
    };
}

