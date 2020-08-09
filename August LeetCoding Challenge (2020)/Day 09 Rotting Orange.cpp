class Solution {
public:
    
    struct orange{
        int count;
        int row, col;
    };
    
    bool valid(int a, int b, vector<vector<int>>& grid){
        return a>=0 && a<grid.size() && b>=0 && b<grid[0].size();
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<orange> q;
        int res = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 2){
                    orange temp;
                    temp.row = i;
                    temp.col = j;
                    temp.count = 0;
                    q.push(temp);
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<q.size(); i++){
                orange temp = q.front();
                q.pop();
                int j = temp.row, k = temp.col;
                vector<vector<int>> movement = {{0,1},{1,0},{-1,0},{0,-1}};
                for(auto move : movement){
                    int r = move[0] + j, c = move[1] + k;
                    if(valid(r,c,grid) && grid[r][c] == 1){
                        grid[r][c] = 2;
                        orange New;
                        New.row = r, New.col = c;
                        New.count = temp.count + 1;
                        res = max(res, New.count);
                        q.push(New);
                    }
                }
            }
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1) return -1;
                
            }
        }
        return res;
    }
};
