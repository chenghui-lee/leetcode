// Solution 1 using library
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) sort(nums.begin(), nums.end());
    }
};

// Solution 2
/*
@DyXrLxSTAOadoD
[2,3,6,5,4,1]
Step1, from right to left, find the first number which not increase in a ascending order. In this case which is 3.
Step2, here we can have two situations:

   1. We cannot find the number, all the numbers increasing in a ascending order. 
      This means this permutation is the last permutation, we need to rotate back to the first permutation. So we reverse the whole array
      
   2. We can find the number, then the next step, we will try to find the closest number which is larger than 3.In this case it is 4.
      Then we swap 3 and 4, the list turn to 2,4,6,5,3,1.
      Last, we sort the numbers at the right of 4, we finally get 2,4,1,3,5,6
   
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1, val = 0, n = nums.size();
        
        for(int i=n-2; i>=0; i--){
            if (nums[i] < nums[i+1]){
                idx = i;
                val = nums[i];
                break;
            }
        }
        if (idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=n-1; i>=0; i--){
            if (nums[i] > val){
                swap(nums[i], nums[idx]);
                break;
            }
        }
        reverse(nums.begin()+idx+1, nums.end()); 
    }
};
