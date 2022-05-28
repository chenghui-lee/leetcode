class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = n * ((double)(1 + n) / 2);
        //cout << sum << "\n";
        for(int x : nums){
            sum -= x;
        }
        return sum;
    }
};
