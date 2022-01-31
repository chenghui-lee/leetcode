class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(int i=0; i<accounts.size(); i++){
            int mon = 0;
            for(int j=0; j<accounts[i].size(); j++){
                mon +=accounts[i][j];
            }
            res = max(res, mon);
        }
        return res;
    }
};
