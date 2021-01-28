class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        for(int i=0; i<n; i++){
            res += 'a';
            k--;
        }
        
        for(int i=n-1; i>=0 && k > 0; i--){
            int t = 0;
            while(t < 25 && k){
                t++;
                k--;
            }
            res[i] = 'a' + t;
        }
        return res;
    }
};
