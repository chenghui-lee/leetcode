class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int positive = 0, negative = 0, res = 0;
        
        for(int x : nums){
            if (x == 0){
                positive = 0, negative = 0;
            }else if (x > 0){
                positive++;
                if (negative > 0) negative++;
            }else{
                if (negative > 0) negative++;
                positive++;
                swap(positive, negative);
            }
            res = max(res, positive);
        }
        return res;
    }
};
