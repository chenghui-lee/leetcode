// O(M) query time
class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {

        for(auto row:matrix){
            vector<int> arr(row.size()+1);
            for(int i=0; i<row.size(); i++){
                arr[i+1] = arr[i] + row[i];
            }
            sum.push_back(arr);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        col2++;
        int temp = 0;
        for(int i=row1; i<=row2; i++){
            temp += sum[i][col2] - sum[i][col1];
        }
        return temp;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

// O(1) query time
// dp[i][j] = sum from origin, box like
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> temp(m+1, vector<int>(n+1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                temp[i+1][j+1] = temp[i+1][j] + temp[i][j+1] - temp[i][j] + matrix[i][j];
            }
        }       
        dp = temp;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }
};
