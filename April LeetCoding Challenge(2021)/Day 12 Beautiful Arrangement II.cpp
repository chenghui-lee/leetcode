class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int l = 1, r = k+1;
        vector<int> res;
        while(l <= r){
            res.push_back(l++);
            if (l <= r) res.push_back(r--);
        }
        for(int i=k+2; i<=n; i++){
            res.push_back(i);
        }
        return res;
    }
};
