class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() or !matrix[0].size()) return false;
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1;
        while(left < right) {
            int mid = (left + right) >> 1;
            int val = matrix[mid / col][mid % col];
            if(val < target) left = mid + 1;
            else right = mid;
        }
        return matrix[left / col][left % col] == target ? true : false;
    }
};
