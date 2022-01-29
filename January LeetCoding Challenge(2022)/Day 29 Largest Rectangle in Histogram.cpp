class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        left[0] = -1;
        right[n-1] = n;
        
        for(int i=1; i<n; i++){
            int idx = i-1;
            while(idx >=0 && heights[idx] >= heights[i]){
                idx = left[idx];
            }
            left[i] = idx;
        }
        
        for(int i=n-2; i>=0; i--){
            int idx = i + 1;
            while(idx < n && heights[idx] >= heights[i]){
                idx = right[idx];
            }
            right[i] = idx;
        }
        
        int res = 0;
        for(int i=0; i<n; i++){
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};
