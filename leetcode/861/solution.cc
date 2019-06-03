class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if(!A.size()) return 0;
        int m = A.size(), n = A[0].size();
        int res = (1 << (n - 1)) * m;
        for(int j = 1; j < n; j++) {
            int oneCount = 0;
            for(int i = 0; i < m; i++) {
                if(A[i][j] == A[i][0]) oneCount++;
            }
            int count = oneCount > m - oneCount ? oneCount : m - oneCount;
            res += (1 << (n - j - 1)) * count;
        }
        return res;
    }
};
