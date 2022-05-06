class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        for(char x : s){
            if (st.empty() || st.top().first != x){
                st.push({x, 1});
            }else{
                if (st.top().second + 1 == k){
                    for(int i=0; i<k-1; i++) st.pop();
                }else{
                    st.push({x, st.top().second + 1});
                }
            }
        }
      // adding char to behind, then reverse is much better than adding infront
      // adding infront will Memory limit exceeded
        string res = "";
        while(!st.empty()){
            res += st.top().first;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
