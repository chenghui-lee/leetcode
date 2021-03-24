class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> st(A.begin(), A.end());
        vector<int> res;
        
        for(int i=0; i<B.size(); i++){
            auto it = st.upper_bound(B[i]);
            if (it != st.end()){
                res.push_back(*it);
                st.erase(it);
            }else{
                res.push_back(*st.begin());
                st.erase(st.begin());
            }
        }
        return res;
    }
};
