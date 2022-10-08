/*
Idea: Sort the array, then loop over all number as
first number. For the other 2 number, use binary 
search to find the closest one
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int curMin = INT_MAX, n = nums.size(), res = 0;
        
        for(int i=0; i<nums.size()-2; i++){
            if(i==0 || nums[i] != nums[i-1]){
                int j = i+1, k = n-1;
                int bal = target - nums[i];
                while(j < k){
                    if (curMin > abs(nums[i] + nums[j] + nums[k] - target)){
                        res = nums[i] + nums[j] + nums[k];
                        curMin = abs(nums[i] + nums[j] + nums[k] - target);
                    }
                    if (nums[j] + nums[k] > bal) k--;
                    else if (nums[j] + nums[k] < bal) j++;
                    else return target;
                }
            }
        }
        
        return res;
    }
};
