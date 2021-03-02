class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> res;
        for(auto x : nums){
            if (s.count(x)) res.push_back(x);
            s.insert(x);
        }
        for(int i=1; i<=nums.size(); i++){
            if (!s.count(i)){
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};

// O(1) Space, O(n) time
vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        for(auto x : nums){
            if (nums[abs(x)-1] < 0) res[0] = abs(x);
            else nums[abs(x)-1] *= -1;
        }
        for (int i=0;i<nums.size();i++) {
            if (nums[i] > 0) res[1] = i+1;
        }
        return res;
}
