class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, vector<int> (), 0, res);
        return res;
    }

private:
    void dfs(vector<int> nums, vector<int> subset, int pos, vector<vector<int>>& res) {
        if(pos == nums.size()) {
            res.push_back(subset);
            return ;
        }
        subset.push_back(nums[pos]);
        dfs(nums, subset, pos + 1, res);
        subset.pop_back();
        dfs(nums, subset, pos + 1, res);
    }
};
