// O(N) space
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size(), even = 0;
        deque<int> dq;
        
        for(int x : nums){
            if (x % 2 == 0) dq.push_front(x);
            else dq.push_back(x);
        }
        return vector(dq.begin(), dq.end());
    }
};

// O(1) space
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even = 0, cur = 0;
        for(; cur < nums.size(); cur++){
            if (nums[cur] % 2 == 0) swap(nums[even++], nums[cur]);
        }
        return nums;
    }
};
