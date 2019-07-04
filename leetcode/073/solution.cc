class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        bool rowZero = false, colZero = false;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(j == 0 && matrix[i][0] == 0)
                    rowZero = true;
                if(i == 0 && matrix[0][j] == 0)
                    colZero = true;
                if(i > 0 && j > 0 && matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                } 
            }
        }
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(rowZero) for(int i = 0; i < row; i++) matrix[i][0] = 0;
        if(colZero) for(int j = 0; j < col; j++) matrix[0][j] = 0;
    }
};
