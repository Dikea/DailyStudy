class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                int left = j - 1, right = j;
                int leftVal = left >= 0 ? triangle[i - 1][left] : INT_MAX;
                int rightVal = right < triangle[i - 1].size() ? triangle[i - 1][right] : INT_MAX;
                triangle[i][j] += min(leftVal, rightVal);
            }
        }
        int minSum = INT_MAX;
        for(int j = 0; j < triangle[n - 1].size(); j++) {
            minSum = min(minSum, triangle[n - 1][j]);
        }
        return minSum;
    }
};
