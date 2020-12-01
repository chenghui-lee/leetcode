/*
Idea: If current number is smaller than the back of the stack, we remove the last element from the stack, while checking
for available digit inside the stack and the number of elements inside the array.

*/

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
