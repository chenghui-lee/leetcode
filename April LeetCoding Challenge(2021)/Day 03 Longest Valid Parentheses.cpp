/*

For every ‘(’ encountered, we push its index onto the stack.

For every ‘)’ encountered, we pop the topmost element and subtract the current element's index from the top element of the stack,
which gives the length of the currently encountered valid string of parentheses. 

If while popping the element, the stack becomes empty, we push the current element's index onto the stack. 
In this way, we keep on calculating the lengths of the valid substrings, and return the length of the longest valid string at the end.


*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, cur = 0;
        
        vector<int> st{-1};
        for(int i=0; i<s.size(); i++){
            auto ch = s[i];
            if (ch == '(') st.push_back(i);
            else{
                st.pop_back();
                if (st.size()){
                    res = max(res, i - st.back());
                }
                else{
                    st.push_back(i);
                }
            }
        }
        return res;
        
        
    }
};
