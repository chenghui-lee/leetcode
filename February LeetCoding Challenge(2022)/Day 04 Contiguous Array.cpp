class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m; // val, index
        int result = 0, sum = 0;
        for (int i =0 ;i<nums.size(); i++){
            if (nums[i] == 1){
                sum ++;
            }else {
                sum --;
            }
        
            auto it = m.find(sum);
            if (sum == 0){ // if same number of 0 and 1
                result = max(result, i+1);
            }else if (it != m.end()){ // if previously meet the value, xxx{0,1,1,0}
                result = max(result, i - it->second);
            }else{
                m.insert({sum, i});
            }
        }
        return result;
    }
};
