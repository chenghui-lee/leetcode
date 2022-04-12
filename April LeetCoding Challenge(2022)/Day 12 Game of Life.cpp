class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int ones = 0;
                
                for(int newRow = i-1; newRow < i+2; newRow++){
                    for(int newCol = j-1; newCol < j+2; newCol++){
                        if (newRow >=0 && newRow<m && newCol >= 0 && newCol<n && abs(board[newRow][newCol]) == 1){
                            ones++;
                        }
                    }
                }
                if (board[i][j] == 1) ones--; // self not included
                if (ones == 3 && board[i][j] == 0) board[i][j] = 2; // revive
                else if ((ones > 3|| ones < 2)&& board[i][j] == 1) board[i][j] = -1; // dead
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (board[i][j] >= 1) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};
