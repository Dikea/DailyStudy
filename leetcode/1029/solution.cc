class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int>& v1, vector<int>& v2){
            return (v1[0] - v1[1]) < (v2[0] - v2[1]);
        }); 
        int res = 0;
        int n = costs.size();
        for(int i = 0; i < n / 2; i++) {
            int j = n - i - 1;
            res += costs[i][0] + costs[j][1];
        }
        return res;
    }
};
