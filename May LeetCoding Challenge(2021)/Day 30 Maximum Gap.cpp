// https://leetcode.com/problems/maximum-gap/discuss/50694/12ms-C%2B%2B-Suggested-Solution
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        auto temp = minmax_element(begin(nums), end(nums));
        auto mn = *temp.first, mx = *temp.second;
        
        int gap = max((mx - mn)/(n-1), 1);
        int m = (mx - mn) / gap + 1;
        
        vector<int> bucketMax(m, INT_MIN);
        vector<int> bucketMin(m, INT_MAX);
        
        for(auto x : nums){
            int i = (x - mn) / gap;
            bucketMax[i] = max(bucketMax[i], x);
            bucketMin[i] = min(bucketMin[i], x);
        }
        int i = 0, j;
        gap = bucketMax[0] - bucketMin[0];
        while(i < m){
            j = i + 1;
            while(j < m && bucketMax[j] == INT_MIN && bucketMin[j] == INT_MAX) j++;
            if (j == m) break;
            gap = max(gap, bucketMin[j] - bucketMax[i]);
            i = j;
        }
        return gap;
    }
};
