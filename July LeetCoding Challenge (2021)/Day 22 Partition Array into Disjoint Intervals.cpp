class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> front(n), back(n);
        
        int mx = INT_MIN, mn = INT_MAX;
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
            front[i] = {mn, mx};
        }
        mx = INT_MIN, mn = INT_MAX;
        for(int i=n-1; i>=0; i--){
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
            back[i] = {mn, mx};
        }
        int i = 0;
        while(i < n-1 && front[i].second > back[i+1].first){
            i++;
        }
        return i+1;
    }
};
