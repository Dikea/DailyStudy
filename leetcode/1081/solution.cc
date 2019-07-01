class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> cnt(26, 0), used(26, 0);
        for(auto ch : text) cnt[ch - 'a']++;
        string res = "";
        for(auto ch : text) {
            cnt[ch - 'a']--;
            if(used[ch - 'a'] > 0) continue;
            while(!res.empty() && res.back() > ch && cnt[res.back() - 'a'] > 0) {
                used[res.back() - 'a']--;
                res.pop_back();
            }
            used[ch - 'a']++;
            res.push_back(ch);
        }
        return res;
    }
};
