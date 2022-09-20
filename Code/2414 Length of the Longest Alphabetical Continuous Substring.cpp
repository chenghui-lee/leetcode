class Solution {
public:
    int longestContinuousSubstring(string s) {
        if (s.size() <= 1) return s.size();
        int res = 0, cur = 1;
        for(int i=1; i<s.size(); i++){
            if (s[i] - s[i-1] == 1) cur++;
            else cur = 1;
            res = max(res, cur);
        }
        return res;
    }
};