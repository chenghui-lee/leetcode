class Solution {
public:
    void backtrack(vector<string>& res, string s, int open, int close, int max){
        if (s.size() == max*2){
            res.push_back(s);
            return;
        }
        if (open < max){
            backtrack(res, s+'(', open+1, close, max);
        }
        if (close < open){
            backtrack(res, s+')', open, close+1, max);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
};
