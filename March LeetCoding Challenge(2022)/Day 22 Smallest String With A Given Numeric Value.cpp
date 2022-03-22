class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<char> res(n, 'a');
        k -=n;
        
        int i = n-1;
        for(; i>=0 && k; i--){
            int t = 0;
            while(t < 25 && k){
                t++;
                k--;
            }
            res[i] = 'a' + t;
        }
        //cout << (char)('a' + 24);
        return string(res.begin(), res.end());
        
    }
};
