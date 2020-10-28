class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return vector<string>();
        else if (nums.size() == 1) return {to_string(nums[0])};
        vector<string> res;
        
        for(int i=0; i<nums.size(); i++){
            int first = nums[i];
            while(i + 1 < nums.size() && nums[i+1] - 1 == nums[i]){
                i++;
            }
            if (first != nums[i]){
                res.push_back(to_string(first) + "->" + to_string(nums[i]));
            }else{
                res.push_back(to_string(first));
            }
        }
        return res;
     }
};
