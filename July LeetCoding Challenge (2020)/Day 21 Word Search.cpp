class Solution {
public:
    bool found(string &word, int i, int j, int index, vector<vector<char>>& board, vector<vector<bool>>& visited){
        if (index >= word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) return false;
        visited[i][j] = true;
        if(found(word, i+1, j, index+1, board, visited) || found(word, i, j+1, index+1, board, visited) || found(word, i-1, j, index+1, board, visited) || found(word, i, j-1, index+1, board, visited)) return true;
        
        visited[i][j] = false;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false)); 
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == word[0] && found(word, i, j, 0, board, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    
};
