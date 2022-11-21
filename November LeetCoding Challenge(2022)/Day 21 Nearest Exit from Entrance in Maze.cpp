class Solution {
public:
    bool isOutOfBound(vector<vector<char>>& maze, int i, int j){
        return i < 0 || i >= maze.size() || j < 0 || j >= maze[0].size();
    }
    bool isValid(vector<vector<char>>& maze, vector<vector<bool>>& visited, int i, int j){
        return maze[i][j] == '.' && !visited[i][j];
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> moves = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int steps = 0;
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = 1;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto [x, y] = q.front(); q.pop();
                for(auto m : moves){
                    int newX = m[0] + x;
                    int newY = m[1] + y;
                    if (isOutOfBound(maze, newX, newY)){
                        if (x != entrance[0] || y != entrance[1]){
                            return steps;
                        }               
                    }else if (isValid(maze, visited, newX, newY)){
                        q.push({newX, newY});
                        visited[newX][newY] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
