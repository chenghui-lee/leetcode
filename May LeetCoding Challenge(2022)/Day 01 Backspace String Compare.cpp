class Solution {
public:
    string help(string s){
        string res = "";
        for(char x : s){
            if (x != '#') res += x;
            else if (x =='#' && res.size() > 0) res.pop_back();
        }
        return res;
    }
    
    bool backspaceCompare(string s, string t) {
        return help(s) == help(t);
    }
};
