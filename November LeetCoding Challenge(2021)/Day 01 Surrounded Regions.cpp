class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& b){
        if (i < 0 || i == b.size() || j < 0 || j == b[0].size() || b[i][j] != 'O'){
            return;
        }
        b[i][j] = 'T';
        dfs(i+1, j, b);
        dfs(i, j+1, b);
        dfs(i-1, j, b);
        dfs(i, j-1, b);
    }
    void solve(vector<vector<char>>& board) {
        // first and last row
        for(int j=0; j<board[0].size(); j++){
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board.back()[j] == 'O') dfs(board.size()-1, j, board);
        }
        // first and last col
        for(int i=0; i<board.size(); i++){
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][board[0].size()-1] == 'O') dfs(i, board[0].size()-1, board);
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if (board[i][j] == 'T') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
