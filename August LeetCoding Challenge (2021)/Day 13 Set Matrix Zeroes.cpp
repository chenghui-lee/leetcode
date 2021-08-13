// O(m+n) space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto r : row){
            for(int j=0; j<matrix[r].size(); j++) matrix[r][j] = 0;
        }
        for(auto c : col){
            for(int i=0; i<matrix.size(); i++) matrix[i][c] = 0;
        }
    }
};

// O(1) space
// use first col / row as marker
// but since row0 and col0 sharing same coordinate (0,0)
// first col 0 != first row zero
// additional booleann is used to check whether the first col is 0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool col0 = false;
        
        for(int i=0; i<m; i++){
            if (matrix[i][0] == 0) col0 = true;
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0, matrix[0][j] = 0;
                }
            }
        }
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if (col0) matrix[i][0] = 0;
        }
    }
};
