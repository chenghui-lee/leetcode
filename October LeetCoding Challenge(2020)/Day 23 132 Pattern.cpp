class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // s1, s2, s3 given s1 < s3 < s2
        int s3 = INT_MIN;
        stack<int> s;
        for(int i=nums.size()-1; i>=0 ;i--){
            if (nums[i] < s3) return true;
            else{
                while(!s.empty() && s.top() < nums[i]){
                    s3 = s.top();
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
    }
};
