class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto num : asteroids) {
            if(num > 0) {
                res.push_back(num);
            }
            else {
                while(!res.empty() && res.back() > 0 && res.back() < abs(num)) {
                    res.pop_back();
                }
                if(res.empty()) res.push_back(num);
                else {
                    if(res.back() < 0) res.push_back(num);
                    else if(res.back() == abs(num)) res.pop_back();
                }
            }
        }
        return res;
    }
};
