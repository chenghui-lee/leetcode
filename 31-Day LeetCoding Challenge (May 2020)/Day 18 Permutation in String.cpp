class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        vector<int> mask(26,0);
        vector<int> tocheck(26,0);
        for (int i =0 ; i<m; i++){
            mask[s1[i] -'a'] += 1;
            tocheck[s2[i] - 'a'] += 1;
        }
        for (int  i = m; i<n; i++){
            if (mask == tocheck) return true;
            tocheck[s2[i] - 'a'] += 1;
            tocheck[s2[i-m] - 'a']--;
        }
        if (mask == tocheck) return true;
        return false;
        
    }
};
