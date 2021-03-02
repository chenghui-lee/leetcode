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
