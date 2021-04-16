class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; // char, count
        
        for(int i=0; i<s.size(); i++){
            if (st.size() && st.top().first == s[i]){
                auto p = st.top();
                if (p.second + 1 == k){
                    for(int j=0; j<p.second; j++) st.pop();
                }else{
                    st.push({s[i], p.second+1});
                }
            }else{
                st.push({s[i], 1});
            }
        }
        string res = "";
        while(st.size()){
            res = st.top().first + res;
            st.pop();
        }
        return res;
    }
};
