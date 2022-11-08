class Solution {
public:

    bool isGood(char a, char b){
        if ((a == b) || (tolower(a) != tolower(b))) return true;
        return false;
    }

    string makeGood(string s) {
        if (s.size() == 0) return s;
        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if (st.empty() || isGood(st.top(), s[i])){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
