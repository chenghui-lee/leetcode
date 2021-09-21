class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26, 0);
        for(auto& ch : s){
            count[ch - 'a']++;
        }
        sort(begin(count), end(count), greater<int>()); // sort desc
        unordered_set<int> st;
        
        int res = 0;
        for(int i=0; i<26; i++){
            if (count[i] == 0 || st.find(count[i]) == st.end()){
                st.insert(count[i]);
                continue;
            }
            while(count[i] != 0 && st.find(count[i]) != st.end()){
                count[i]--;
                res++;
            }
            st.insert(count[i]);
        }
        return res;
    }
};
