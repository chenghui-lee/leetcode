class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(), flip = 0, one = 0;
        
        for(int i=0; i<n; i++){
            if (s[i] == '1') one++;
            else flip++;
            flip = min(one, flip);
        }
        
        return flip;
    }
};
