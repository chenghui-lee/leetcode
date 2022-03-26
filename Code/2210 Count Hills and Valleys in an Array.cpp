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

// O(n) time, O(1) space
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        
        int i=1, res = 0;
        
        while(i < n && nums[i] == nums[i-1]) i++;
        int prevIdx = i - 1;
        
        for(; i<n-1; i++){
            if (nums[i] == nums[i+1]) continue;
            res += (nums[i] > nums[prevIdx]) == (nums[i] > nums[i+1]);
            prevIdx = i;
        }
        return res;
    }
};
