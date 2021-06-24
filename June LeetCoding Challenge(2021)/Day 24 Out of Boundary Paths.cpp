class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int MOD = 1e9 + 7;
        vector<vector<vector<long>>> dp(maxMove+1, vector<vector<long>>(m, vector<long>(n, 0)));
        // dp[N][i][j] = num of possible path to reach i, j from outside, given at most N steps
        
        vector<vector<int>> moves = {{0,1},{1,0},{-1,0},{0,-1}};
        
        for(int N=1; N<=maxMove; N++){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    for(auto mv: moves){
                        int x = i + mv[0], y = j + mv[1];
                        if (x < 0 || x >= m || y < 0 || y >=n){ // if out of bound
                            dp[N][i][j] += 1;
                        }else{
                            dp[N][i][j] = (dp[N][i][j] + dp[N-1][x][y] + MOD) % MOD;
                        }
                    }
                }
            }
        }
        return dp[maxMove][startRow][startColumn] % MOD;
    }
};
