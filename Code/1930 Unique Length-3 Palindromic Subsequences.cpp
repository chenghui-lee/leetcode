/*
Idea: 

For each character (a-z), we find the leftmost and rightmost index
then count the unique char in between them.

*/
class Solution {
public:
    int countUnique(int i, int j, string s){
        unordered_set<char> st;
        for(;i<j; i++){
            st.insert(s[i]);
        }
        return st.size();
    }
    
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> idx(26, {-1, -1}); // leftmost and rightmost index of char
        int n = s.size();
        
        for(int i=0; i<n; i++){
            if (idx[s[i] - 'a'].first == -1){
                idx[s[i] - 'a'].first = i;
            }else{
                idx[s[i] - 'a'].second = i;
            }
        }
        
        int res = 0;
        for(int i=0; i<26; i++){
            if (idx[i].second == -1) continue; // only single occurance
            res += countUnique(idx[i].first+1, idx[i].second, s);
        }
        return res;
    }
};
