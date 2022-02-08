class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd,even;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if (i % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(odd.rbegin(), odd.rend());
        sort(begin(even), end(even));
        
        int j = 0, k = 0;
        for(int i=0; i<n; i++){
            if (i % 2 == 0) nums[i] = even[j++];
            else nums[i] = odd[k++];
        }
        return nums;
        
    }
};
