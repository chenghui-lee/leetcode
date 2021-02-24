class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, depth = 0;
        for(int i=0; i<S.size(); i++){
            if (S[i] == '(') depth++;
            else depth--;
            if (i && S[i] == ')' && S[i-1] == '(') res += 1 << depth;
        }
        return res;
    }
};
