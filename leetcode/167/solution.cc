class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int val = target - numbers[i];
            int left = i + 1, right = n - 1;
            while(left < right) {
                int mid = (left + right) >> 1;
                if(numbers[mid] < val) left = mid + 1;
                else right = mid;
            }
            if(numbers[left] == val) {
                ans = vector<int> {i + 1, left + 1};
                break;
            }
        }
        return ans;
    }
};
