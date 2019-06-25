class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, res = 0;
        for(int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            while(left < right && right - left + 1 - 
                  *max_element(count.begin(), count.end()) > k) {
                count[s[left] - 'A']--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
