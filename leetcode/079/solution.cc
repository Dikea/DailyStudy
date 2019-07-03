class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(dfs(board, word, i, j))
                    return true;
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>> &board, string word, int x, int y) {
        if(word.empty()) return true;
        int row = board.size(), col = board[0].size();
        if(x < 0 || y < 0 || x >= row || y >= col || board[x][y] != word[0]) return false;
        char ch = board[x][y];
        board[x][y] = '_';
        word = word.substr(1);
        bool ret = (dfs(board, word, x - 1, y) 
                    || dfs(board, word, x + 1, y)
                    || dfs(board, word, x, y - 1)
                    || dfs(board, word, x, y + 1));
        board[x][y] = ch;
        return ret;
    }
};
