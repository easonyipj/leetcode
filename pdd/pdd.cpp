//
// Created by Eason on 2019/7/28.
//
//    3.
//    int n;
//    int m;
//    cin>>n>>m;
//    int status[n + 1];
//    vector<int> timetable(n + 1);
//
//    string s1;
//    getline(cin, s1);
//    for(int i = 0; i < s1.length();) {
//        string s;
//        while(i < s1.length() && s1[i] != ' ') {
//            s += s1[i];
//            i++;
//        }
//        timetable.push_back(atoi(s.c_str()));
//        i++;
//    }






//    2.
//    vector<string> vec;
//    string s1;
//    getline(cin, s1);
//    map<char, int> kmap;
//    for(int i = 0; i < s1.length();) {
//        string s;
//        while(i < s1.length() && s1[i] != ' ') {
//            s += s1[i];
//            i++;
//        }
//        vec.push_back(s);
//        if(kmap[s[0]] > 0) {
//            kmap[s[0]]++;
//        }else{
//            kmap[s[0]] = 1;
//        }
//
//        if(kmap[s[s.length() - 1]] > 0) {
//            kmap[s[s.length() - 1]]++;
//        }else {
//            kmap[s[s.length() - 1]] = 1;
//        }
//        i++;
//    }
//
//    map<char, int>::iterator it = kmap.begin();
//    while(it != kmap.end()) {
//        if(it->second % 2 != 0) {
//            cout<<"false"<<endl;
//            return 0;
//        }
//        it++;
//    }
//
//    cout<<"true"<<endl;
//    return 0;
//for(int i = 0; i <)

//    // 先检查第一个字符串和最后一个能否拼接
//    if(vec[0][0] != vec[vec.size() - 1][vec[vec.size() - 1].length() - 1]) {
//        cout<<"false"<<endl;
//        return 0;
//    }
//
//    // 检查中间的字符串
//    for(int i = 0; i < vec.size() - 1; i++) {
//        if(vec[i][vec[i].length() - 1] != vec[i + 1][0]) {
//            cout<<"false"<<endl;
//            return 0;
//        }
//    }
//
//    cout<<"true"<<endl;

//      1.
//    string s1;
//    string s2;
//
//    getline(cin, s1);
//    getline(cin, s2);
//
//    vector<int> vec1;
//    vector<int> vec2;
//
//    for(int i = 0; i < s1.length();) {
//        string s;
//        while(i < s1.length() && s1[i] != ' ') {
//            s += s1[i];
//            i++;
//        }
//        vec1.push_back(atoi(s.c_str()));
//        i++;
//    }
//
//    for(int i = 0; i < s2.length();) {
//        string s;
//        while(i < s2.length() && s2[i] != ' ') {
//            s += s2[i];
//            i++;
//        }
//        vec2.push_back(atoi(s.c_str()));
//        i++;
//    }
//
//    int index = -1;
//    int index2 = -1;
//
//    // 第一个数不符合升序
//    if(vec1[0] > vec1[1]) {
//        index = 0;
//    }else if(vec1[0] == vec1[1]) {
//        index = 0;
//        index2 = 1;
//    }
//    else{
//        for(int i = 0; i < vec1.size() - 1; i++) {
//            // 大于的情况
//            if(vec1[i] > vec1[i + 1] ) {
//                index = i + 1;
//            }
//
//            // 等于的情况
//            if(vec1[i] == vec1[i + 1]) {
//                index = i + 1;
//                index2 = i;
//            }
//        }
//    }
//
//    sort(vec2.begin(), vec2.end());
//
//    int ans = -1;
//
//    for(int i = 0; i < vec2.size(); i++) {
//        if(index == 0 && vec2[i] < vec1[index + 1] ) {
//            ans = i;
//        }
//        else if(index == vec2.size() - 1 && vec2[i] > vec1[index - 1]) {
//            ans = i;
//        }
//        else if(vec2[i] > vec1[index - 1] && vec2[i] < vec1[index + 1]) {
//            ans = i;
//        }
//    }
//
//    if(ans == -1) {
//        if(index2 != -1) {
//            for(int i = 0; i < vec2.size(); i++) {
//                if(index2 == 0 && vec2[i] < vec1[index2 + 1] ) {
//                    ans = i;
//                }
//                else if(index2 == vec2.size() - 1 && vec2[i] > vec1[index2 - 1]) {
//                    ans = i;
//                }
//                else if(vec2[i] > vec1[index2 - 1] && vec2[i] < vec1[index2 + 1]) {
//                    ans = i;
//                }
//            }
//        }
//        if(ans == -1) {
//            cout<<"NO"<<endl;
//        }else{
//            vec1[index2] = vec2[ans];
//        }
//    }else{
//        vec1[index] = vec2[ans];
//    }
//
//    for(int i = 0; i < vec1.size(); i++) {
//        cout<<vec1[i];
//        cout<<" ";
//    }
//
//    return 0;
