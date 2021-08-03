class Solution {
public:
    set<vector<int>> res;
    
    void permute(vector<int>& nums, vector<int>& cur, int index){
        res.insert(cur);
        for(int i=index; i<nums.size(); i++){
            cur.push_back(nums[i]);
            permute(nums, cur, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> cur;
        permute(nums, cur, 0);
        vector<vector<int>> ans;
        for(auto p : res) ans.push_back(p);
        return ans;
    }
    
};
// check during permute, so no set used
// https://leetcode.com/problems/subsets-ii/discuss/30164/Accepted-10ms-c%2B%2B-solution-use-backtracking-only-10-lines-easy-understand.
class Solution {
public:
    vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
		sort(nums.begin(), nums.end());
    vector<vector<int> > res;
		vector<int> vec;
		subsetsWithDup(res, nums, vec, 0);
		return res;
    }
private:
	void subsetsWithDup(vector<vector<int>> &res, vector<int> &nums, vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) { 
				vec.push_back(nums[i]);
				subsetsWithDup(res, nums, vec, i + 1);
				vec.pop_back();
			}
	}
};
