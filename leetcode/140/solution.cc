class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, 0);
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            for(auto w : wordDict) {
                if(i + w.size() <= n && s.substr(i, w.size()) == w) {
                    if(dp[i] == true)
                        dp[i + w.size()] = dp[i];
                }
            }
        }
        vector<string> res;
        dfs(res, s, "", n, wordDict, dp);
        return res;
    }

private:
    void dfs(vector<string>& res, string s, string cur, int pos, 
             vector<string>& wordDict, vector<bool>& dp) {
        if(pos == 0) {
            res.push_back(cur);
            return ;
        }
        if(!dp[pos]) return ;
        for(auto w : wordDict) {
            int newPos = (int)pos - (int)w.size();
            if(newPos >= 0 && s.substr(newPos, w.size()) == w) {
                string newCur = (cur == "" ? w : w + " " + cur);
                dfs(res, s, newCur, newPos, wordDict, dp);
            }
        }
    }
};
