class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size(); i++){
            if (i==0 || nums[i] != nums[i-1]){
                
                int lower = i+1;
                int upper = nums.size()-1;
                int target = 0 - nums[i];
                while(lower<upper){
                    if (nums[lower] + nums[upper] == target){
                        vector<int> ans;
                        ans.push_back(nums[i]);  
                        ans.push_back(nums[lower]);
                        ans.push_back(nums[upper]);
                        result.push_back(ans);

                        while(lower < upper && nums[lower]==nums[lower+1]) lower++;
                        while(lower < upper && nums[upper]==nums[upper-1]) upper--;
                        lower++;
                        upper--;
                    }
                    else if (nums[lower] + nums[upper] > target){
                        upper--;
                    }else{
                        lower++;
                    }
                }
            }

        }
        return result;
    }
};
