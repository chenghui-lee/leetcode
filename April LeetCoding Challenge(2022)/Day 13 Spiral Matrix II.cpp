class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n, vector<int>(n));
        int rowStart = 0, rowEnd = n-1, colStart = 0, colEnd = n-1;
        
        int nums = 1;
        while(rowStart <= rowEnd && colStart <= colEnd){
            for(int i=colStart; i<= colEnd; i++){
                res[rowStart][i] = nums++;
            }
            rowStart++;
            for(int i=rowStart; i <= rowEnd; i++){
                res[i][colEnd] = nums++;
            }
            colEnd--;
            for(int i=colEnd; i>=colStart; i--){
                if (rowStart <= rowEnd) res[rowEnd][i] = nums++;
            }
            rowEnd--;
            for(int i=rowEnd; i>=rowStart; i--){
                if (colStart <= colEnd) res[i][colStart] = nums++;
            }
            colStart++;
            
        }
        
        return res;
    }
};
