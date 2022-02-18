class Solution {
public:
    string removeKdigits(string nums, int k) {
        if (k >= nums.size()) return "0";
        vector<char> stk;
        
        for(int i=0; i<nums.size(); i++){
            while(k > 0 && !stk.empty() && stk.back() > nums[i]){
                k--;
                stk.pop_back();
            }
            stk.push_back(nums[i]);
        }
        while(k--){
            stk.pop_back();
        }
        string res;
        int i =0;
        while(i < stk.size() && stk[i] == '0'){
            i++;
        }
        for(; i<stk.size(); i++){
            res += stk[i];
        }
        return res.empty() ? "0" : res;
        
        
    }
};
