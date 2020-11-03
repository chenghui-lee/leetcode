class Solution {
public:
    int maxPower(string s) {
        int count = 1, res = 1;
        for(int i=1; i<s.size(); i++){
            if (s[i] == s[i-1]) count++;
            else count = 1;
            res = max(res, count);
        }
        return res;
    }
};
