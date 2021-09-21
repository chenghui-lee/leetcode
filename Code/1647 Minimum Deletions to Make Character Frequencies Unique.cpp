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
// another way
class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26, 0);
        for(auto& ch : s){
            count[ch - 'a']++;
        }
        sort(begin(count), end(count));
        
        int res = 0;
        int large = count[25];
        for(int i=25; i>=0; i--){
            if (count[i] > large){
                res += count[i] - large;
                count[i] = large;
            }
            large = max(count[i] - 1, 0);
        }
        return res;
    }
};
