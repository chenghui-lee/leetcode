class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int start =0, end = 0;
        int res = 0;
        
        while(end < s.size()){
            if (!st.count(s[end])){
                st.insert(s[end]);
                end++;
                res = max(res, (int)st.size());
            }else{
                st.erase(s[start]);
                start++;
            }
        }
        return res;
    }
};
