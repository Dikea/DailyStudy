class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(!board.size()) return ;
        int n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) {
                int cnt = 0;
                for(int ii = max(0, i - 1); ii <= min(n - 1, i + 1); ii++)
                    for(int jj = max(0, j - 1); jj <= min(m - 1, j + 1); jj++) {
                        if(ii == i && jj == j) continue;
                        if(board[ii][jj] & 1) cnt++;
                    }
                if(board[i][j] == 1 && (cnt == 2 || cnt == 3))
                    board[i][j] |= 2;
                if(board[i][j] == 0 && cnt == 3) 
                    board[i][j] |= 2;
            }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
