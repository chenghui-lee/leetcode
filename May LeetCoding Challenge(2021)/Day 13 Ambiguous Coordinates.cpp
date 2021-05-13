/*
In split function, 

if S == "": return []
if S == "0": return [S]
if S == "0XXX0": return []
if S == "0XXX": return ["0.XXX"]
if S == "XXX0": return [S]
return [S, "X.XXX", "XX.XX", "XXX.X"...]

*/
class Solution {
public:
    vector<string> split(string s){
        int n = s.size();
        if (n == 0 || (n > 1 && s[0] == '0' && s[n-1] == '0')) return {};
        if (n > 1 && s[0] == '0') return {"0." + s.substr(1)};
        if (n == 1 || s[n-1] == '0') return {s};
        
        vector<string> temp = {s};
        for(int i=1; i<n; i++){
            temp.push_back(s.substr(0, i) + '.' + s.substr(i));
        }
        return temp;
    }
    
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> res;
        
        for(int i=1; i<n-2; i++){
            vector<string> a = split(s.substr(1, i));
            vector<string> b = split(s.substr(i+1, n-2-i));
            for(auto x : a){
                for (auto y : b){
                    res.push_back("(" + x + ", " + y + ")");
                }
            }
        }
        
        return res;
    }
};
