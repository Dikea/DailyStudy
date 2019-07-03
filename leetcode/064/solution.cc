class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vals(m, vector<int> (n, INT_MAX));
        vals[0][0] = grid[0][0];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i > 0) vals[i][j] = min(vals[i][j], vals[i - 1][j] + grid[i][j]);
                if(j > 0) vals[i][j] = min(vals[i][j], vals[i][j - 1] + grid[i][j]);
            }
        }
        return vals[m - 1][n - 1];
    }
};
