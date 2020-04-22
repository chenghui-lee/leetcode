class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int sum = 0, res = 0;
    for (int i = 0; i<nums.size(); i++){
    	sum += nums[i];
    	if (sum == k){
    		res ++;
    	}
    	if (m[sum-k]){
    		res += m[sum-k];
    	}
        m[sum]++;
    }
    return res;
}
};

// reference : https://leetcode.com/problems/subarray-sum-equals-k/discuss/591787/C%2B%2B-Simple-Solution-and-Explanation
