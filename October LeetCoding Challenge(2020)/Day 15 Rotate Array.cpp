// Solution 1:
// Rotate the whole array, then rotate the first k element, finally rotate the rest
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size()==0 || k%nums.size() == 0) return;
        
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};


// Solution 2: 
// Placing the element to the place where it should be after rotation, keep replacing until the currentIndex is equal to the starting index. Then move on to second element.
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
