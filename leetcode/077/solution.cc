class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(res, n, k, 0, vector<int> {});
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& res, int n, int k, int cur, vector<int> comb) {
        if(comb.size() == k) {
            res.push_back(comb);
            return ;
        }
        for(int i = cur + 1; i <= n; i++) {
            comb.push_back(i);
            dfs(res, n, k, i, comb);
            comb.pop_back();
        }
    }
};
