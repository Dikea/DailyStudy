class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> res;
        for(auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto v : graph[u]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    q.push(v);
                    res.push_back(v);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int> {};
    }
};
