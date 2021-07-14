class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> m(26);
        for(auto ch : str){
            m[ch - 'a']++;
        }
        int idx = 0, n = str.size();
        
        for(auto ch : order){
            while(m[ch - 'a']-- > 0) str[idx++] = ch;
        }
        for(int i=0; i<26; i++){
            while(m[i]-- > 0) str[idx++] = ('a' + i);
        }
        return str;
    }
};
