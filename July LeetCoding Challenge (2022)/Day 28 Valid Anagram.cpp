class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26),b(26);
        
        for(auto x : s) a[x - 'a']++;
        for(auto x : t) b[x - 'a']++;
        return a == b;
    }
};
