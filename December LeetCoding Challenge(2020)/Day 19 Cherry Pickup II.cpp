class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
        
        for(int i=r-1; i>=0; i--){
            for(int x1=0; x1<c; x1++){
                for(int x2=0; x2<c; x2++){
                    int res = 0;
                    res += grid[i][x1] + ((x1==x2)?0:grid[i][x2]); // if same pos, take only 1
                    
                    if (i != r-1){ // not last row, can go down
                        int mx = 0;
                        for(int newX1 = x1-1; newX1 <= x1 + 1; newX1++){
                            for(int newX2 = x2-1; newX2 <= x2 + 1; newX2++){
                                if (newX1>=0 && newX1<c && newX2>=0 && newX2 <c){
                                    mx = max(mx, dp[i+1][newX1][newX2]);
                                }
                            }
                        }
                        res += mx;
                    }
                    dp[i][x1][x2] = res;
                }
            }
        }
        return dp[0][0][c-1];
    }
};
