// valid triangle is a + b < c
// where a <= b <= c

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        
        sort(nums.rbegin(), nums.rend());
        int n = nums.size(), res = 0;
        
        for(int c = 0; c < n-2; c++){
            int b = c+1, a = n-1;
            while(a > b){
                if (nums[a] + nums[b] > nums[c]){
                    res += (a-b);
                    b++;
                }else{
                    a--;
                }
            }
        }
        return res;
    }
};
