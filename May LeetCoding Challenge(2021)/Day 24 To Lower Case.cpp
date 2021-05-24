class Solution {
public:
    string toLowerCase(string s) {
        int d = 'A' - 'a';
        for(auto& x : s){
            if (x >= 'A' && x <= 'Z') x -= d;
        }
        return s;
    }
};
