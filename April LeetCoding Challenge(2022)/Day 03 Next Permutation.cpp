/*
Idea: From right to left, find an index where it it smaller than it's right one.
If all of them are sorted in descending order, we have no next permutation.

If we found the index, find one more index from the right which is larger than the current number.
Then swap it, and reverse the list behind of the current index.

1 5 8 4 7 6 5 3 1
      ^ nums[i] < nums[i+1]
    
1 5 8 4 7 6 5 3 1
      ^     ^ first number greater than 4, swap
      
1 5 8 5 7 6 4 3 1
      ^ <------->
           rev
1 5 8 5 1 3 4 6 7         

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() -2;
        while(i >= 0 && nums[i] >= nums[i+1]) i--;
        
        if (i>=0){
            int j = nums.size() - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
