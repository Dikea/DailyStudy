class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res{{}};
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        int i = 0;
        while(i < n) {
            int count = 1;
            while(i + count < n && nums[i] == nums[i + count]) {
                count++;
            }
            int preSize = res.size();
            for(int j = 0; j < preSize; j++) {
                vector<int> tmp = res[j];
                for(int t = 0; t < count; t++) {
                    tmp.push_back(nums[i]);
                    res.push_back(tmp);
                }
            }
            i += count;
        }
        return res;
    }
};
