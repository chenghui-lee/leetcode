class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> top(n, vector<int>(n, 0));
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> bottom(n, vector<int>(n, 0));
        
        vector<vector<int>> matrix(n, vector<int>(n, 1));
        for(auto p : mines){
            matrix[p[0]][p[1]] = 0;
        }
        
        int res = mines.size() < n*n ? 1 : 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (matrix[i][j] == 1){
                    top[i][j] = (i-1>=0) ? top[i-1][j]+1 : 1;
                    left[i][j] = (j-1>=0) ? left[i][j-1]+1 : 1;
                }else{
                    top[i][j] = 0, left[i][j] = 0;
                }
            }
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if (matrix[i][j] == 1){
                    bottom[i][j] = (i+1<n) ? bottom[i+1][j]+1 : 1;
                    right[i][j] = (j+1<n) ? right[i][j+1]+1 : 1;
                }else{
                    bottom[i][j] = 0, right[i][j] = 0;
                }
                int cur = min(left[i][j], min(right[i][j], min(top[i][j], bottom[i][j])));
                res = max(res, cur);
            }
        }
        
        return res;
    }
};
