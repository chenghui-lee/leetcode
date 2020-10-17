class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return vector<string>();
        
        string temp = "";
        unordered_set<string> st, res;
        for(int i=0; i<10; i++){
            temp += s[i];
        }
        st.insert(temp);
        for(int i=10; i<s.size(); i++){
            temp.erase(temp.begin());
            temp += s[i];
            if (st.count(temp)){
                res.insert(temp);
            }else{
                st.insert(temp);
            }
        }
        return vector<string> (res.begin(), res.end());
    }
};
