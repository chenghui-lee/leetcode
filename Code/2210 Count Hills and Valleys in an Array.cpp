class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        v.push_back(nums[0]);
        
        for(int i=1; i<n; i++){
            if (nums[i] != nums[i-1]){
                v.push_back(nums[i]);
            }
        }
        n = v.size();
        int res = 0;
        for(int i=1; i<n-1; i++){
            res += (v[i] > v[i-1]) == (v[i] > v[i+1]);
            // both true = hill, both false = valley
        }
        return res;
    }
};
