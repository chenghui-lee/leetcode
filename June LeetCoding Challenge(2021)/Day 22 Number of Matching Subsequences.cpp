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



// TLE, 22/52
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<set<int>> m(26);
        for(int i=0; i<s.size(); i++){
            m[s[i] - 'a'].insert(i);
        }
        
        int res = 0;
        for(auto& w : words){
            int i = -1;
            bool ok = 1;
            if (w.size() > s.size()) continue;
            for(auto& ch : w){
                auto& dict = m[ch - 'a'];
                auto it = upper_bound(dict.begin(), dict.end(), i);
                if (it == dict.end()){
                    ok = 0;
                    break;
                } 
                i = *it;
            }
            if (ok) res++;
        }
        return res;
    }
};
