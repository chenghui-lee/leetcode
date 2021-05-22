class Solution {
public:
    vector<vector<string>> res;
    
    bool valid(vector<string>& board, int row, int col){
        // col
        for(int i=row; i>=0; i--){
            if (board[i][col] == 'Q') return false;
        }
        // left top diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if (board[i][j] == 'Q') return false;
        }
        // top right diagonal
        for(int i=row, j=col; i>=0 && j<board.size(); i--, j++){
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    
    void dfs(vector<string>& board, int row){
        if (row == board.size()){
            res.push_back(board);
            return;
        }
        for(int i=0; i<board.size(); i++){ // col
            if (valid(board, row, i)){
                board[row][i] = 'Q';
                dfs(board, row+1);
                board[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        return res;
    }
};
