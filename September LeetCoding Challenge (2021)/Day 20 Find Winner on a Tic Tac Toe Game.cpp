class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> grid(3, vector<char>(3, '*'));
        for(int i=0; i<moves.size(); i++){
            if (i % 2 == 0){
                grid[moves[i][0]][moves[i][1]] = 'A';
            }else{
                grid[moves[i][0]][moves[i][1]] = 'B';
            }
        }
        // check win condition, row by row
        for(int i=0; i<3; i++){
            if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '*'){
                return string(1, grid[i][0]);
            }
        }
        // check win condition, col by col
        for(int i=0; i<3; i++){
            if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '*'){
                return string(1, grid[0][i]);
            }
        }
        // check win condition, diagonal left
        if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[0][0] != '*'){
            return string(1, grid[0][0]);
        }
        // check win condition, diagonal right
        if(grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0] && grid[0][2] != '*'){
            return string(1, grid[0][2]);
        }
        if (moves.size() == 9) return "Draw";
        else return "Pending";
    }
};
