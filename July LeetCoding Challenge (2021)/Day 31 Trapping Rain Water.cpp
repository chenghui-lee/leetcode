class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        /*
        workflow:
        1. from left to right, find max btwn building & water level
        2. from right to left
        3. find min
        4. find diff and sum it up
        */
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = height[0];
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]);
        }
        int res = 0;
        for(int i=1; i<n; i++){
            res += min(left[i], right[i]) - height[i];
        }
        return res;
    }
};
