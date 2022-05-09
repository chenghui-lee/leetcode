class Solution {
public:
    vector<string> res;
    unordered_map<char, string> dict;
    
    void dfs(string digits, int idx, string cur){
        if (idx == digits.size()){
        if (cur.size() > 0) res.push_back(cur);
            return;
        }
        for(auto ch : dict[digits[idx]]){
            cur += ch;
            dfs(digits, idx+1, cur);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";
        string cur = "";
        dfs(digits, 0, cur);
        return res;
    }
};
