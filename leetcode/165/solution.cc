class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        int n1 = 0, n2 = 0;
        int num1 = 0, num2 = 0;
        while(n1 < len1 || n2 < len2) {
            while(n1 < len1 && version1[n1] != '.') {
                num1 = num1 * 10 + (version1[n1] - '0');
                n1++;
            }
            while(n2 < len2 && version2[n2] != '.') {
                num2 = num2 * 10 + (version2[n2] - '0');
                n2++;
            }
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            num1 = 0, num2 = 0;
            n1++, n2++;
        }
        return 0;
    }
};
