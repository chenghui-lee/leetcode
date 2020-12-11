class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        int n = nums.size();
        
        
        if (n < 3) return n;
        
        int count = 1;
        while(j < n){
            if (nums[j] == nums[i-1]){
                if (count == 2) j++;
                else{
                    nums[i++] = nums[j++];
                    count++;
                }
            }else{
                nums[i++] = nums[j++];
                count = 1;
            }
        }
        return i;
    }
};
