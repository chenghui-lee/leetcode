class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=1; i<=numRows; i++){
            vector<int> cur(i, 1);
            for(int j=1; j<i-1 && i>=3; j++){
                cur[j] = res.back()[j-1] + res.back()[j];
            }
            res.push_back(cur);
        }
        
        return res;
    }
};
