//
// Created by 易平建 on 2019-06-26.
//
#include <vector>

using namespace std;

namespace course{
    class courseSchedule {
    public:
        static bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
            if(prerequisites.empty()) {
                return true;
            }
            vector<int> flag(numCourses, 0);
            vector<vector<int>> adjacentList(numCourses);
            bool ans = true;
            // 生成邻接表
            for(int i = 0; i < prerequisites.size(); i++) {
                adjacentList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
            for(int i = 0; i < numCourses; i++) {
                ans = ans&&dfs(i, flag, adjacentList);
            }
            return ans;
        }
        static bool dfs(int vertax, std::vector<int> &flag, std::vector<std::vector<int>> &adjacentList) {
            if(flag[vertax] == -1) {
                return false;
            }
            if(flag[vertax] == 1) {
                return true;
            }
            flag[vertax] = -1;
            for(int i = 0; i < adjacentList[vertax].size(); i++) {
                if(dfs(adjacentList[vertax][i], flag, adjacentList)) {
                    continue;
                }
                return false;
            }
            flag[vertax] = 1;
            return true;
        }
    };
}



