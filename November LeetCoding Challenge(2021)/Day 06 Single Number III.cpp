/*
Find the XOR for the entire array, since the 2 numbers are distinct, we can find the rightmost one
Then for every number in the array, we can AND this diff.
Numbers will be divided into 2 groups
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long diff = 0;
        for(auto& x: nums){
            diff ^= x;
        }
        long rightmostOne = diff & -diff;
        vector<int> res = {0, 0};
      
        for(auto& x: nums){
            if(x & rightmostOne) res[0] ^= x;
            else res[1] ^= x;
        }
        return res;
    }
};
