class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        if(digits[n] < 9){
            digits[n]++;
            return digits;
        }else{
            digits[n]++;
            for(int i=n;i>=0;i--){
                if (digits[i] >= 10 && i > 0){
                    digits[i-1]++;
                    digits[i] = 0;
                }else if (digits[i] >= 10 && i == 0){
                    digits[i] = 0;
                    digits.insert(digits.begin(), 1);
                }
            }
        }
        return digits;
    }
};
