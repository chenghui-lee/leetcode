/*
Idea:
Split the two arrays into 2 parts, left side and right side

Array 1: x x x | x x x x
Array 2: y y | y y y y

Such that all the elements on the left is less than equals to right side
maxLeftX <= minRightY and maxLeftY <= minLeftX

Then the median can be calculated by
even total length : max(maxLeftX, maxLeftY) + min(minRightX, minRightY) / 2;
odd total length : max(maxLeftX, maxLeftY)

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int x = nums1.size(), y = nums2.size();
        int low = 0, high = x; // low = how many elements on the left side of the partition
        
        while(low <= high){
            int partitionX = (low + high) / 2;
            int partitionY = (x+y+1) / 2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX){
                if ((x + y) % 2 == 0){
                    return double(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                }else{
                    return max(maxLeftX, maxLeftY);
                }
            }else if (maxLeftX > minRightY){
                high = partitionX - 1;
            }else{
                low = partitionX + 1;
            }
        }
        return -1;
    }
};
