class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int zeroCount = 0;
        int left = 0, right = 0;
        int res = 0;
        for(;right < A.size(); right++) {
            if(A[right] == 0) zeroCount++;
            while(zeroCount > K) {
                if(A[left] == 0) zeroCount--;
                left++;
            }
            res = max(res, right - left + 1);
        } 
        return res;
    }
};
