class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rowStart = 0, rowEnd = matrix.size() - 1, colStart = 0, colEnd = matrix[0].size() -1;
        
        while(rowStart <= rowEnd && colStart <= colEnd){
            for(int i=colStart; i<=colEnd; i++){
                res.push_back(matrix[rowStart][i]);
            }
            rowStart++;
            for(int i=rowStart; i<=rowEnd; i++){
                res.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            for(int i=colEnd; i>=colStart; i--){
                if (rowStart <= rowEnd) res.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            for(int i=rowEnd; i>=rowStart; i--){
                if (colStart <= colEnd) res.push_back(matrix[i][colStart]);
            }
            colStart++;
        }
        
        return res;
    }
};
