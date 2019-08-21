//
// Created by Eason on 2019/8/20.
//

#include<iostream>
#include "string"
#include "sstream"
#include "algorithm"
#include "vector"
#include "map"


using namespace std;

namespace str{
    class errorRecord{
    public:
        struct error_codes{
            string filename;
            int codeline;
            int counter=1;
            bool operator==(const error_codes &a){
                if(a.filename==filename&&a.codeline==codeline)
                    return true;
                else
                    return false;
            }

        };

        static string getfilename(string filename){  //从地址字符串中，获取最后的文件名
            // 处理文件名
            vector<string> ss;
            int i = 0;
            while(i < filename.size() && filename[i] != '\0') {
                string s;
                while(i < filename.size() && filename[i] != '\\')  {
                    s += filename[i];
                    i++;
                }

                ss.push_back(s);
                i++;
            }

            char c[16];
            if(ss[ss.size() - 1].size() > 16) {
                ss[ss.size() - 1].copy(c, 16, ss[ss.size() - 1].size() - 16);
                ss[ss.size() - 1] = c;
            }

            return ss[ss.size() - 1];
        }

        static void recordError() {

            vector<error_codes> inputnumber;
            string filename;
            int codeline=0;
            int i=0;

            while(cin>>filename>>codeline){
                error_codes temp;
                temp.filename = getfilename(filename);
                temp.codeline=codeline;
                vector<error_codes>::iterator res;
                res=find(inputnumber.begin(),inputnumber.end(),temp);
                if(res==inputnumber.end()){     //temp不在inpunumber数组中
                    inputnumber.push_back(temp);
                }
                else{
                    res->counter++;
                }
                ++i;
            }
            int j=0;
            if(inputnumber.size()>8)
                j=inputnumber.size()-8;
            for(j;j<inputnumber.size();++j){
                cout<<inputnumber[j].filename<<" "<<inputnumber[j].codeline<<" "<<inputnumber[j].counter<<endl;
            }

        }
    };
}
