class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minVal = 1, maxVal = 1;
        int res = INT_MIN;
        for(int i = 0; i < n; i++) {
            int oldMin = minVal, oldMax = maxVal;
            minVal = min(min(oldMin * nums[i], oldMax * nums[i]), nums[i]);
            maxVal = max(max(oldMin * nums[i], oldMax * nums[i]), nums[i]);
            res = max(res, maxVal);
        }
        return res;
    }
};
