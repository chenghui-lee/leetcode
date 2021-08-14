// https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions
class Solution {
public:
  vector<vector<vector<int>>> dp;
    
  int dfs(const vector<int>& boxes, int i, int j, int k) {
    if (i > j) return 0;    
    if (dp[i][j][k] > 0) return dp[i][j][k];

    dp[i][j][k] = dfs(boxes, i+1, j, 0) + (k + 1) * (k + 1);
      
    for (int m = i + 1; m <= j; m++) {
        if (boxes[i] == boxes[m]) {
            dp[i][j][k] = max(dp[i][j][k], dfs(boxes, i + 1, m - 1, 0) + dfs(boxes, m, j, k + 1));
        }
    }
    return dp[i][j][k];
  }
    
  int removeBoxes(vector<int>& boxes) {
    int n = boxes.size();
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n)));
    return dfs(boxes, 0, n - 1, 0);
  }
};
