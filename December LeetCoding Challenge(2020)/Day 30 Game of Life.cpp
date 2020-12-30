// Space: O(MN)
// Time: O(MN)

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int ones = 0;
                if (i>0) ones += board[i-1][j]; // up
                if (j>0) ones += board[i][j-1]; // left
                if (i<m-1) ones += board[i+1][j]; // down
                if (j<n-1) ones += board[i][j+1]; // right
                if (i>0 && j>0) ones += board[i-1][j-1]; // up left
                if (i>0 && j<n-1) ones += board[i-1][j+1];
                if (i<m-1 && j>0) ones += board[i+1][j-1];
                if (i<m-1 && j<n-1) ones += board[i+1][j+1];
                
                if (ones < 2) res[i][j] = 0;
                else if (ones == 3) res[i][j] = 1;
                else if (ones == 2) res[i][j] = board[i][j];
            }
        }
        board = res;
    }
};

// Space: O(1)
// Time: O(MN)
// Live to dead = -1, dead to live = 2

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
