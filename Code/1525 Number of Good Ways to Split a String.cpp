class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        unordered_set<char> st;
        vector<int> left(n), right(n);
        
        for(int i=0; i<n; i++){
            st.insert(s[i]);
            left[i] = st.size();
        }
        st.clear();
        int res = 0;
        for(int i=n-1; i>=0; i--){
            st.insert(s[i]);
            right[i] = st.size();
        }
        for(int i=0; i<n-1; i++){
            if (left[i] - right[i+1] == 0) res++;
        }
        
        return res;
    }
};
