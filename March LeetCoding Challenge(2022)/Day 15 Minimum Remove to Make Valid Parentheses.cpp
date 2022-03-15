class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int close = count(s.begin(), s.end(), ')');
        int open = 0; // current open bracket, not inc skipped
        string res = "";
        for(char x : s){
            if (x == '('){
                if (open == close){ // if enuf brackets, skip the current (
                    continue;
                }
                open++;
            }else if (x == ')'){
                close--;
                if (open == 0){ // enuf brackets, skip the current )
                    continue;
                }
                open--;
            }
            res += x;
        }
        
        
        return res;
    }
};
