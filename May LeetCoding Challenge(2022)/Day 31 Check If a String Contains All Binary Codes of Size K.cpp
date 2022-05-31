class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<int> st;
        for(int i=0; i+k-1<n; i++){
            st.insert(stoi(s.substr(i, k), 0, 2));
            // stoi(string, idx, base)
        }
        for(int i=0 ;i < (1 << k); i++){
            if (!st.count(i)) return false;
        }
        return true;
    }
};
