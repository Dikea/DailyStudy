class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if(left >= right) return ;
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid - 1);
        quickSort(nums, mid + 1, right);
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int key = nums[left];
        while(left < right) {
            while(left < right && nums[right] >= key) right--;
            nums[left] = nums[right];
            while(left < right && nums[left] < key) left++;
            nums[right] = nums[left];
        }
        nums[left] = key;
        return left;
    }
};
