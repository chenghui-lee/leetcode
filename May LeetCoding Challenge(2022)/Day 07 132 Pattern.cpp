class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int mid = INT_MIN;
        int n = nums.size();
        
        for(int i=n-1; i>=0; i--){
            // treat cur element as the i
            if (nums[i] < mid) return true;
            else{
                // change the mid to highest possible
                while(!s.empty() && s.top() < nums[i]){
                    mid = s.top();
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
    }
};
