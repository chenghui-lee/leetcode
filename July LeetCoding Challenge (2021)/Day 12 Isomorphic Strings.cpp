class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1,m2;
        
        for(int i=0; i<s.size(); i++){
            auto it1 = m1.find(s[i]);
            auto it2 = m2.find(t[i]);
            
            if (it1 == m1.end() && it2 == m2.end()){
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }else{
                if (m1[s[i]] != t[i] || m2[t[i]] != s[i]) return false;
            }
            
        }
        return true;
    }
};

// same idea, using vector
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        vector<int> m1(256, -1);
        vector<int> m2 (256, -1);
        
        for(int i=0; i< s.length(); i++){
            if(m1[s[i]]!=m2[t[i]]) return false;
            m1[s[i]]=i;
            m2[t[i]]=i;
        }
        return true;
    }
};
