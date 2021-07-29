// dp, 2 pass, from top left to bottom right, then bottom right to top left
// pick the min
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int inf = 1e9;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (mat[i][j] == 0) continue;
                int up = (i > 0) ?  dp[i-1][j] : inf;
                int left = (j > 0) ? dp[i][j-1] : inf;
                dp[i][j] = min(up, left) + 1; 
            }
        }
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if (mat[i][j] == 0) continue;
                int down = (i < m-1) ?  dp[i+1][j] : inf;
                int right = (j < n-1) ? dp[i][j+1] : inf;
                dp[i][j] = min(dp[i][j], min(down, right) + 1);
            }
        }
        return dp;
    }
};

// bfs @ https://leetcode.com/problems/01-matrix/discuss/101021/Java-Solution-BFS
public class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    queue.offer(new int[] {i, j});
                }
                else {
                    matrix[i][j] = Integer.MAX_VALUE;
                }
            }
        }
        
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            for (int[] d : dirs) {
                int r = cell[0] + d[0];
                int c = cell[1] + d[1];
                if (r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] <= matrix[cell[0]][cell[1]] + 1) continue;
                queue.add(new int[] {r, c});
                matrix[r][c] = matrix[cell[0]][cell[1]] + 1;
            }
        }
        
        return matrix;
    }
}
