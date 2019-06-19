class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        int res = 0;
        while(l < r) {
            if(people[r] + people[l] <= limit) {
                r--;
                l++;
            }
            else {
                r--;
            }
            res++;
        }
        return res + (l == r ? 1 : 0);
    }
};
