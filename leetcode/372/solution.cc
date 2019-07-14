class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int t = b.back();
        b.pop_back();
        return pow(superPow(a, b), 10) * pow(a, t) % base;
    }

private:
    const int base = 1337;
    int pow(int a, int k) {
        a %= base;
        int res = 1;
        while(k) {
            if(k & 1) res = (res * a) % base;
            a = (a * a) % base;
            k >>= 1;
        }
        return res;
    }
};
