class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        int res = 0;
        for(int x : nums){
            if (s.find(x) == s.end()) continue;
            int prev = x-1, next = x+1;
            while(s.find(prev) != s.end()){
                s.erase(prev--);
            }
            while(s.find(next) != s.end()){
                s.erase(next++);
            }
            res = max(res, next - prev - 1);
        }
        return res;
    }
};
