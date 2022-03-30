class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0;
        while(top < m && target > matrix[top][n-1]){
            top++;
        }
        if (top == m) return false;
        
        int i=0, j=n-1;
        while(i <= j){ // cannot i < j because they will be in the same pos in some cases
            int mid = i + (j-i)/2;
            if (matrix[top][mid] == target) return true;
            else if(matrix[top][mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return false;
    }
};
