class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0 , n = nums.size();
        vector<string> res;
        
        while(i < n){
            int j = i + 1;
            string tmp = to_string(nums[i]);
            while(j < n && nums[j-1] + 1 == nums[j]) j++;
            if (j-1 != i){
                tmp += "->" + to_string(nums[j-1]);
            }
            res.push_back(tmp);
            i = j;
        }
        return res;
    }
};
