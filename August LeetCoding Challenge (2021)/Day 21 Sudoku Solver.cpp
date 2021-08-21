class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if (board[i][j] != '.') continue;
                for(char ch = '1'; ch<='9'; ch++){
                    if (isValid(board,i,j,ch)){
                        board[i][j] = ch;
                        if (solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    } 
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        int regionRow = 3* (row/3);
        int regionCol = 3* (col/3);
        
        for(int i=0; i<9; i++){
            if (board[row][i] == c || board[i][col] == c) return false; // row and col
            if (board[regionRow + i/3][regionCol + i%3] == c) return false; // 3x3 box
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
