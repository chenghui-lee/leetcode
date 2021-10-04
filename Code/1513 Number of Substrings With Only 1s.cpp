class Solution {
public:
    int numSub(string s) {
        int res = 0, count = 0;
        int MOD = 1e9 + 7;
        for(int i=0; i<s.size(); i++){
            if (s[i] == '1') count++;
            else count = 0;
            res = (res + count) % MOD;
        }
        return res;
    }
};
