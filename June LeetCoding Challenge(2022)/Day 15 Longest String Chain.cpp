class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> m; // string, number of word ending in this word
        sort(begin(words), end(words), [](const auto& s1, const auto& s2){ return s1.size() < s2.size();});
        
        int res = 0;
        for(auto x : words){
            for(int i=0; i<x.size(); i++){
                string temp = x.substr(0, i) + x.substr(i+1); // removing 1 char 
                m[x] = max(m[x], m[temp]+1);
            }
            res = max(res, m[x]);
        }
        return res;
    }
};
