class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0 || matrix[0].size() == 0) return false;
        
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, left = 0, right = matrix[0].size() -1;
        
        while(top < m && matrix[top][n-1] < target){
            top++;
        }
        if (top == m) return false;
        while(left <= right){
            int mid = (left + right) / 2;
            if (matrix[top][mid] == target) return true;
            else if (matrix[top][mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
