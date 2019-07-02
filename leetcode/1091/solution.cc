class Solution {
public:
    struct Node {
        int x, y, val;
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1|| grid[n - 1][n - 1] == 1) {
            return -1;
        }
        
        queue<Node> q;
        q.push({0, 0, 1});
        while(!q.empty()) {
            Node node = q.front();
            q.pop();
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    int x = node.x + i, y = node.y + j;
                    if(x < 0 || x >= n || y < 0 || y >= n 
                       ||(i == 0 && j == 0) || grid[x][y] == 1) {
                        continue;
                    }
                    if(x == n - 1 && y == n - 1) {
                        return node.val + 1;
                    }
                    q.push({x, y, node.val + 1});
                    grid[x][y] = 1;
                }
            }
        }
        return -1;
    }
};
