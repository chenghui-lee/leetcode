class Solution {
public:
    int concatenatedBinary(int n) {
        int MOD = 1e9 + 7;
        long res = 0;
        for(int i=1; i<=n; i++){
            int bitLen = log2(i)+1;
            res = ((res << bitLen)+i)  % MOD;
        }
        return (int)res;
    }
};
