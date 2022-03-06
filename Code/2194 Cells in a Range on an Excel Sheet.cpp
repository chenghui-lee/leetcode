class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> res;
        for(char A = s[0]; A<=s[3]; A++){
            for(char B = s[1]; B <=s[4]; B++){
                string t= "";
                t.push_back(A);
                t.push_back(B);
                
                res.push_back(t);
            }
        }
        return res;
    }
};
