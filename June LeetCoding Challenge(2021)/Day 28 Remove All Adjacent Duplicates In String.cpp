class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(auto& ch : s){
            if (!st.empty() && st.top() == ch){
                st.pop();
                continue;
            }
            st.push(ch);
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end()); // use this instead of appending at front, faster
        return res;
    }
};
