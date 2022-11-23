class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> num;
        // check col
        for(int i=0; i<9; i++){
            num = vector<bool>(10, false);
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                int idx = board[i][j] - '0';
                if (num[idx]) return false;
                num[idx] = 1;
            }
        }
        // checking row
        for(int i=0; i<9; i++){
            num = vector<bool>(10, false);
            for(int j=0; j<9; j++){
                if(board[j][i] == '.') continue;
                int idx = board[j][i] - '0';
                if (num[idx]) return false;
                num[idx] = 1;
            }
        }
        // check box
        int rowStart = 0, colStart = 0;
        while(rowStart < 9){
            num = vector<bool>(10, false);
            for(int i=rowStart; i<rowStart+3; i++){
                for(int j=colStart; j<colStart+3; j++){
                    if (board[i][j] == '.') continue;
                    auto idx = board[i][j] - '0';
                    if (num[idx]) return false;
                    num[idx] = true;
                }
            }
            if (colStart < 9) colStart+=3;
            if (colStart == 9){
                colStart = 0, rowStart+=3;
            }
        }
        return true;
    }
};
