class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> combination(target + 1,0); // somehow must be unsigned, idk why
        combination[0] = 1;
        
        for(int i=1; i<=target; i++){
            for(int j=0; j<nums.size(); j++){
                if (i - nums[j] >= 0){
                    combination[i] += combination[i-nums[j]];
                }
            }
        }
        return combination[target];
    }
};
