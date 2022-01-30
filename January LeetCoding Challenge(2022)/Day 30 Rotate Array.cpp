class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int count = 0;
        for(int start =0; count < nums.size(); start++){
            int currentIndex = start;
            int prev =  nums[start];
            
            do {
                int nextIndex = (currentIndex + k) % nums.size();
                int temp = nums[nextIndex];
                nums[nextIndex] = prev;
                prev = temp;
                currentIndex = nextIndex;
                count++;
            }while(start != currentIndex);
        }
    }
};
