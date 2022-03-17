class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0, n = s.size();
        int layer = 0;
        for(int i=0; i<n; i++){
            if (s[i] == '(') layer++;
            else{
                layer--;
                if (i > 0 && s[i-1] == '('){
                    res += 1 << layer;
                }
            }
        }
        return res;
            
    }
};
