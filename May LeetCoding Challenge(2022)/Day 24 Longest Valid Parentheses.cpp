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
