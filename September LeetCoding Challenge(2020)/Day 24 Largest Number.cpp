class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        if(nums.size() == 0) return res;
        for(int i=0; i<nums.size()-1;i++){
            for(int j=i+1; j<nums.size(); j++){
                string temp1 = to_string(nums[i]) + to_string(nums[j]);
                string temp2 = to_string(nums[j]) + to_string(nums[i]);
                if (temp1.compare(temp2) < 0) swap(nums[i], nums[j]);
            }
        }
        
        for(int x : nums){
            res += to_string(x);
        }
        while(*res.begin() == '0' && res.size() > 1){
            res.erase(res.begin());
        }
        return res;
    }
};
