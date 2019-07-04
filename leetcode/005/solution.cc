class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        string longString = s.substr(0, 1);
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j] && (dp[i + 1][j - 1] > 0 || j == i + 1)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if(j - i + 1 > longString.size()) {
                        longString = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return longString;
    }
};
