class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        double check = log(n)/log(2);
        int mask = (int) check;
        return abs(check-mask)<=(1e-9);
    }
};
