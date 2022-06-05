class Solution {
public:
    int res = 0;
    unordered_set<int> colSet, leftDiagSet, rightDiagSet;
    
    void helper(int row, int n){
        if (row == n){
            res++;
            return;
        }
        for(int col=0; col<n; col++){
            if (colSet.find(col) != colSet.end()) continue;
            if (leftDiagSet.find(row - col) != leftDiagSet.end()) continue;
            if (rightDiagSet.find(row + col) != rightDiagSet.end()) continue;
            
            // backtracking
            colSet.insert(col);
            leftDiagSet.insert(row - col);
            rightDiagSet.insert(row + col);
            
            helper(row+1, n);
            
            colSet.erase(col);
            leftDiagSet.erase(row - col);
            rightDiagSet.erase(row + col);
        }
    }
    
    int totalNQueens(int n) {
        helper(0, n);
        return res;
    }
};
