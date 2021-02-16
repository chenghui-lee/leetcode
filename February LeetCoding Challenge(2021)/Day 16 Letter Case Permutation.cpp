class Solution {
public:
    void dfs(string& s, vector<string>& res, int idx){
        if (idx == s.size()-1){
            if (isalpha(s[idx])){
                res.push_back(s);
                s[idx] = change(s[idx]);
            }
            res.push_back(s);
            return;
        }
        dfs(s, res, idx+1);
        if (isalpha(s[idx])){
            s[idx] = change(s[idx]);
            dfs(s, res, idx+1);
        }
        
    }
    char change(char ch){
        return (tolower(ch)==ch)?toupper(ch):tolower(ch);
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        dfs(S, res, 0);
        return res;
    }
    
};
