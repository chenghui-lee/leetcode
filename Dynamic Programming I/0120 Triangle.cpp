class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                int choice = INT_MAX;
                if (j-1 >=0) choice = min(choice, triangle[i-1][j-1]);
                if (j <= i-1) choice = min(choice, triangle[i-1][j]);
                triangle[i][j] += choice;
            }
        }
        int res = INT_MAX;
        for(auto x : triangle.back()){
            res = min(res, x);
        }
        return res;
    }
};
