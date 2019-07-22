class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++) dp[i][i] = true;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                    if(i + 1 == j) dp[i][j] = true;
                }
            }
        }
        vector<vector<string>> res;
        dfs(res, s, {}, 0, dp);
        return res;
    }
    
private:
    void dfs(vector<vector<string>>& res, string s, vector<string> cur, 
             int pos, vector<vector<bool>>& dp) {
        if(pos == s.size()) {
            res.push_back(cur);
            return;
        }
        int n = s.size();
        for(int i = pos; i < n; i++) {
            if(dp[pos][i]) {
                cur.push_back(s.substr(pos, i - pos + 1));
                dfs(res, s, cur, i + 1, dp);
                cur.pop_back();
            }
        }
    }
};
