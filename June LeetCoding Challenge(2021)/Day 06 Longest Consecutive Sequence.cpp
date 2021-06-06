// Sorting n log n
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int cur = 1, res = 1;
        for(int i=1; i<nums.size(); i++){
            if (nums[i-1] == nums[i]) continue;
            if ((long)nums[i]-1 == nums[i-1]){
                res = max(res, ++cur);
            }else cur = 1;
        }
        return res;
    }
};

// unordered_set, O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        int res = 0;
        for(auto x : nums){
            if (s.find(x) == s.end()) continue;
            s.erase(x);
            int prev = x-1, next = x+1;
            while(s.find(prev) != s.end()) s.erase(prev--);
            while(s.find(next) != s.end()) s.erase(next++);
            res = max(res, next - prev - 1);
        }
        return res;
    }
};
