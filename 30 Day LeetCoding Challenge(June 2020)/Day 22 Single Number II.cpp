class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones =0, twos = 0, mask;
        for(int i=0; i<nums.size(); i++){
            twos |= (ones & nums[i]); // storing the element appear twice
            ones ^= nums[i]; // storing the element that appear once
            mask = ~(ones & twos); // the element that appear third times
            ones &= mask, twos &= mask; // remove it from ones and twos
        }
        return ones;
    }
};

// another idea

int singleNumber(vector<int>& nums) {
    // ones - storing element that appear once, twos - appear twice
        int ones =0, twos = 0;
        for(int i=0; i<nums.size(); i++){
            ones = (ones^nums[i]) & ~(twos);
    	    twos = (twos^nums[i]) & ~(ones);
        }
        return ones;
    }
