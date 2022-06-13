class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        
        for(int i=1; i<triangle.size(); i++){
            int n = triangle[i].size();
            vector<int> temp(n);
            for(int j=0; j<n; j++){
                if (j == 0){
                    temp[j] = dp[j] + triangle[i][j];
                }else if (j == n-1){
                    temp[j] = dp[j-1] + triangle[i][j];
                }else{
                    temp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
                }
            }
            dp = temp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
