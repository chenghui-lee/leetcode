// KMP
// Time: O(s + p)
// Space: O(p)

class Solution {
public:
    vector<int> build(string p){
        int m = p.size();
        vector<int> table(m+1);
        
        int i = 0, j = -1;
        table[0] = -1;
        
        while(i < m){
            while(j>=0 && p[i] != p[j]) j = table[j];
            i++, j++;
            table[i] = j;
        }
        return table;
    }
    
    int strStr(string haystack, string needle) {
        if (needle.size() == 0 || haystack.size() == 0 && needle.size() == 0) return 0;
        vector<int> table = build(needle);
        int i =0, j=0, a = haystack.size(), b = needle.size();
        
        while(i < a){
            while(j>=0 && haystack[i] != needle[j]) j = table[j];
            i++, j++;
            if (j == b) return i - j;
        }
        return -1;
    }
};
