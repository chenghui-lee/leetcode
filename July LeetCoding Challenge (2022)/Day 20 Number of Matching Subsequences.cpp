class Solution {
public:
    bool isSubSeq(string s, string t){
        int i = 0, j = 0, m = s.size(), n = t.size();
        
        while(i < m && j < n){
            if (s[i] == t[j]){
                i++, j++;
            }else{
                i++;
            }
        }
        return j==n;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> m; // string, count
        
        for(auto& w : words){
            m[w]++;
        }
        
        int res = 0;
        for(auto it=m.begin(); it!=m.end(); it++){
            if (isSubSeq(s, it->first)) res += it->second;
        }
        return res;
    }
};
