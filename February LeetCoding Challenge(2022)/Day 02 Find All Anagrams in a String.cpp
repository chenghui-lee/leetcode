class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> mask(26, 0);
        for(auto ch : p){
            mask[ch - 'a']++;
        }
        
        int n = s.size();
        vector<int> res;
        vector<int> cur(26, 0);
        
        for(int i=0; i<p.size(); i++){
            cur[s[i] -'a']++;
        }
        if (cur == mask) res.push_back(0);
        for(int i=p.size(); i<n; i++){
            cur[s[i - p.size()] - 'a']--;
            cur[s[i] - 'a']++;
            if (cur == mask) res.push_back(i-p.size()+1);
        }
        return res;
    }
};
