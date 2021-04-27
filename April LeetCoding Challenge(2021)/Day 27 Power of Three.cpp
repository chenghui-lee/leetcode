class Solution {
public:
    //https://stackoverflow.com/questions/1804311/how-to-check-if-an-integer-is-a-power-of-3
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int t = log2(n)/log2(3);
        return pow(3, t) == n;
    }
};

// another sol, cant use log10, got conversion error (decimal point)
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int d = int(log2(n)/log2(3));
        return pow(3, d) == n;
    }
