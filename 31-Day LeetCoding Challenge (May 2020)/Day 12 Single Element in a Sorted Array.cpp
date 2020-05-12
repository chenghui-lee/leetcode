// [1,1,2,2,3,4,4,5,5]
// i_star is the variable to determine the position of pair to check
// if the current index is even, we should check index +1, else index -1
// if the both element is the same, the single element must be on the right side of the middle element
// else the single element is on the left side of the middle element
// Reference : https://www.youtube.com/watch?v=uJa9Q-05JxY

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while (left < right){
            mid = left + (right-left)/2;
            int i_star; // i star can be set as mid^1
            if (mid % 2 == 0) i_star = mid+1;
            else i_star = mid-1;
            if (nums[mid] == nums[i_star]){
                left = mid +1;
            }else{
                right = mid;
            }
        }
        return nums[left];
        
    }
};
