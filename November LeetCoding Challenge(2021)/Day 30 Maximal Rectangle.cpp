// https://www.youtube.com/watch?v=g8bSdXCG-lA
// https://leetcode.com/problems/maximal-rectangle/discuss/29054/Share-my-DP-solution
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<int> left(n, 0);
        vector<int> right(n, n-1);
        vector<int> height(n, 0);
        int res = 0;
        
        for(int i=0; i<m; i++){
            int curLeft = 0, curRight = n-1;
            // compute height
            for(int j=0; j<n; j++){
                if (matrix[i][j] == '1'){
                    height[j]++;
                }else height[j] = 0;
            }
            // compute left
            for(int j=0; j<n; j++){
                if (matrix[i][j] == '1'){
                    left[j] = max(left[j], curLeft);
                }else{
                    left[j] = 0;
                    curLeft = j+1;
                }
            }
            // compute right
            for(int j=n-1; j>=0; j--){
                if (matrix[i][j] == '1'){
                    right[j] = min(right[j], curRight);
                }else{
                    right[j] = n-1;
                    curRight = j-1;
                }
            }
            // compute result
            for(int j=0; j<n; j++){
                res = max(res,(right[j]-left[j]+1)*height[j]);
            }
            
        }
        return res;
    }
};
