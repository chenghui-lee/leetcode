class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;
        for(int i =0; i<nums.size(); i++){
            if (s.find(i) == s.end()){
                int j = i;
                int count = 0;
                while(s.find(j) == s.end()){
                    count++;
                    s.insert(j);
                    j = nums[j];
                }
                res = max(res, count);
            }
            
        }
        return res;
    }
};
