//2021/8/7
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0), topological;
        for (const auto &pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            ++indegree[pre[0]];
        }
        queue<int> Q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                Q.push(i);
            }
        }
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            topological.push_back(u);
            for (const int &v : adjList[u]) {
                --indegree[v];
                if (indegree[v] == 0) {
                    Q.push(v);
                }
            }
        }
        if (topological.size() < numCourses) {
            topological.clear();
        }
        return topological;
    }
};