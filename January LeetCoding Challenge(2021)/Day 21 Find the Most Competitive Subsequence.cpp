class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            while(!res.empty() && res.back() > nums[i] && res.size() -1 + nums.size() - i >= k){
                res.pop_back();
            }
            if (res.size() < k) res.push_back(nums[i]);
        }
        
        return res;
    }
};
