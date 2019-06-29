class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }
        queue<int> q;
        int counter = 0;
        for(int i = 0; i < numCourses; i++)
            if(inDegree[i] == 0) {
                q.push(i);
                counter++;
            }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto v : graph[u]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    q.push(v);
                    counter++;
                }
            }
        }
        return counter == numCourses;
    }
};
