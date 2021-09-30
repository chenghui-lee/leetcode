// sol 1. loop through each subset, put any numbers inside
class Solution {
public:
    
    bool canSum(vector<int>& nums, vector<bool>& visited, int index, int target, int kLeft, int curSum){
        if (kLeft == 1) return true; // we know the remain one confirm can sum up to k
        
        if (curSum == target){
            return canSum(nums, visited, 0, target, kLeft - 1, 0);
        }
        for(int i=index; i<nums.size(); i++){
            if (!visited[i] && curSum + nums[i] <= target){
                visited[i] = 1;
                if (canSum(nums, visited, i+1, target, kLeft, curSum + nums[i])) return true;
                visited[i] = 0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        
        int target = sum / k;
        vector<bool> visited(n, false);
        sort(nums.begin(), nums.end(), greater<int>());
        return canSum(nums, visited, 0, target, k, 0);
    }
};

// sol 2. loop through all numbers, put into any subset
