class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        for(auto x :words){
            if (x.size() != pattern.size()) continue;
            unordered_map<char, char> a, b;
            bool ok = 1;
            
            for(int i=0; i<x.size(); i++){
                if (a.find(x[i]) == a.end() && b.find(pattern[i]) == b.end()){
                    a[x[i]] = pattern[i];
                    b[pattern[i]] = x[i];
                }
                else if (a.find(x[i]) == a.end() || b.find(pattern[i]) == b.end() || a[x[i]] != pattern[i] || b[pattern[i]] != x[i]){
                    ok = 0;
                    break;
                }
            }
            if (ok) res.push_back(x);
        }
        
        return res;
    }
};
