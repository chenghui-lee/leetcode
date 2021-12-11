class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long lcm = a*b / __gcd(a,b);
        long low = 2, high = (long)1e9 * min(a,b);
        long MOD = 1e9 + 7;
        
        while(low < high){
            long m = (low + high) / 2;
            if (m/a + m/b - m/lcm < n){
                low = m + 1;
            }else high = m;
        }
        return low % MOD;
    }
};
