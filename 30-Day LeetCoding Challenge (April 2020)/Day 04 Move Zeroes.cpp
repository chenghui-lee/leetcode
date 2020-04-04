class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
	for (int pass = 0; pass<nums.size()-1; pass++){
		for (int i = 0; i<nums.size()-1; i++){
			if (nums[i] == 0){
				nums[i] = nums[i+1];
				nums[i+1] = 0;
			}
		}
	}

}
};
// Since the question specifies it must be done in-place, so we can use bubble sort concept
// it's slow, but works
