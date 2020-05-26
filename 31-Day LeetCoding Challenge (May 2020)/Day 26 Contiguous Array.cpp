// This question is a repetitive question from April 30d challenge
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mapp; // sum and index
        int result = 0, sum = 0;
        for (int i = 0; i<nums.size(); i++){
            if (nums[i] == 1){
                sum += 1;
            }else{
                sum -= 1;
            }
            auto x = mapp.find(sum);
            
            //if the sum == 0, means that number of 1 and 0 are the same, so we check if it is longer than the result.
            if (sum == 0){
                if (i+1 > result){
                    result = i+1;
                }
            }
            // if the sum is not zero and the sum is found, we check the length of the index , replace if needed
            else if (x != mapp.end()){
                if (i-x->second > result){
                    result = i-x->second;
                }
            }
            // if the sum is not zero and the sum is encounte before, we add in into the map
            else if (x == mapp.end()){
                mapp.insert({sum, i});
            }
        }
        return result;
    }
};
