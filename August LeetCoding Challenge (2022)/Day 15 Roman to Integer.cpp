class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        for(int i=0; i<s.size(); i++){
            res += m[s[i]];
            if (i > 0){
                if (m[s[i]] > m[s[i-1]]){
                    res -= 2 * m[s[i-1]];
                }
            }
        }
        
        return res;
    }
};
