// 1st solution, using heap
// much slower

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        
        if (k==1) return nums;

        multiset<int> ms;
        for(int i=0; i<k; i++){
            ms.insert(nums[i]);
        }
        res.push_back(*ms.rbegin());
        for(int i=k; i<nums.size(); i++){
            ms.insert(nums[i]);
            ms.erase(ms.find(nums[i - k]));           
            res.push_back(*ms.rbegin());                                
        }
        return res;
    }
};
