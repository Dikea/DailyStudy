class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            if(nums[l] < nums[r]) return nums[l];
            int mid = (l + r) >> 1;
            if(nums[mid] > nums[r]) l = mid + 1;
            else if(nums[mid] < nums[r]) r = mid;
            else r--;
        }
        return nums[l];
    }
};
