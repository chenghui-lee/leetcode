// https://leetcode.com/problems/find-the-duplicate-number/solution/
// Tortoise and hare
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1 = nums[0], p2 = nums[0]; // p1 for tortoise, p2 for hare
        do{ // find intersection point
            p1 = nums[p1];
            p2 = nums[nums[p2]];
        }while(p1 != p2);
        
        // find entrance for the loop
        p1 = nums[0];
        while(p1 != p2){
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return p1;
    }
};
