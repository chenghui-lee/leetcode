class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26, 0);
        unordered_set<int> st; // store the unique frequency
        
        for(char x : s) count[x - 'a']++;
        int res = 0;
        for(int i=0; i<26; i++){
            if (count[i] == 0) continue;
            while(count[i] > 0 && st.find(count[i]) != st.end()){
                count[i]--;
                res++;
            }
            st.insert(count[i]);
        }
        return res;
    }
};
