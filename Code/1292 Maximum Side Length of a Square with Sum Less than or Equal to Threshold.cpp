// 1179 ms
class Solution {
public:
    int sumRange(vector<vector<int>>& dp, int row1, int col1, int row2, int col2){
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        bool minOne = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i+1][j+1] = mat[i][j] + dp[i][j+1] + dp[i+1][j] - dp[i][j];
                if (mat[i][j] <= threshold) minOne = 1;
            }
        }
        int maxsz = min(m, n);
        for(int size=maxsz; size>1; size--){
            for(int i=0; i+size-1<m; i++){
                for(int j=0; j+size-1<n; j++){
                    if (sumRange(dp, i, j, i+size-1, j+size-1) <= threshold){
                        return size;
                    }
                }
            }
        }
        return minOne == true ? 1 : 0;
        
        
        
    }
};

// some modification to speed up to 128ms
class Solution {
public:
    int sumRange(vector<vector<int>>& dp, int row1, int col1, int row2, int col2){
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        bool minOne = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i+1][j+1] = mat[i][j] + dp[i][j+1] + dp[i+1][j] - dp[i][j];
            }
        }
        int sz = 0;
        int maxsz = min(m, n);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                while(i - sz >= 0 && j - sz >= 0 && sumRange(dp, i-sz, j-sz, i, j) <= threshold){
                    sz++;
                }
                if (sz == maxsz) return sz;
            }
        }
        return sz;
    }
};
