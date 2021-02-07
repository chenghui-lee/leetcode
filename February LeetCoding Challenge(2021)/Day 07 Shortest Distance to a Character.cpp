// From left and from right, pick the min
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, n);
        
        int idx = -n;
        for(int i=0; i<n; i++){
            if (s[i] == c) idx = i;
            res[i] = i - idx;
        }
        for(int i=n-1; i>=0; i--){
            if (s[i] == c) idx = i;
            res[i] = min(res[i], idx - i);
        }
        
        return res;
    }
};
