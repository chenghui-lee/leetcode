class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if (c == '(' || c == '[' || c == '{'){
                stk.push_back(c);
            }else{
                if (stk.empty()) return false;
                char x = stk.back();
                if ((x == '(' && c != ')') || (x == '[' && c != ']') || (x == '{' && c != '}')) {
                    return false;
                }
                stk.pop_back();
            }
        }
        return stk.empty();
    }
};
