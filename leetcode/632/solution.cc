class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> res{0, INT_MAX};
        vector<pair<int, int>> total;
        for(int i = 0; i < n; i++) {
            for(auto v : nums[i]) {
                total.push_back(make_pair(v, i));
            }
        }
        sort(total.begin(), total.end());
        unordered_map<int, int> mm;
        int m = total.size();
        int count = 0;
        int left = 0, right = 0;
        for(; right < m; right++) {
            mm[total[right].second]++;
            if(mm[total[right].second] == 1) count++;
            while(count == n) {
                if(total[right].first - total[left].first < res[1] - res[0]) {
                    res = {total[left].first, total[right].first};
                }
                if(mm[total[left].second] == 1) count--;
                mm[total[left].second]--;
                left++;
            }
        }
        return res;
    }
};
