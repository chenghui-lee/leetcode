class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> m;
        vector<string> res;
        if (digits.size() == 0) return res;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        res.push_back("");
        
        for (auto num : digits){
            vector<string> temp;
            for(auto ch : m[num - '0']){
                for(auto curRes : res){
                    temp.push_back(curRes + ch);
                }
            }
            res = temp;
        }
        return res;
        
        
    }
};
