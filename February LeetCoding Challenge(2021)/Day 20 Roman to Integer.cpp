class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        int res = 0;

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        for(int i=0; i<s.size(); i++){
            if (i > 0 && m[s[i]] > m[s[i-1]]) res -= 2*m[s[i-1]];
            res += m[s[i]];
        }
        return res;
    }
};
