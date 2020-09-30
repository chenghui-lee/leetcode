class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x : nums){
            s.insert(x);
        }
        for(int i=1; i<=INT_MAX; i++){
            if (!s.count(i)) return i;
        }
        return 1;
    }
};

// O(n) time, O(1) space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            while (nums[i]>0 && nums[i]<=n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i=0; i<n; i++){
            if (nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};
