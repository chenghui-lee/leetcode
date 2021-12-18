class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int k = s.size(), d = digits.size();
        
        // add number of combinations for digit less than k
        int res = 0;
        for(int i=1; i<k; i++){
            res += pow(d, i);
        }
        
        for(int i=0; i<k; i++){
            bool needToCheck = 0;
            for(auto x : digits){
                if (x[0] < s[i]){
                    res += pow(d, k-i-1); // 1xxxx for 22333
                }else if (x[0] == s[i]){
                    needToCheck = 1; // need to check for the next digit of num
                    break; // because the remaining digit from digits are confirm to be larger than s[i]
                }
            }
            if (!needToCheck) return res;
        }
        return res + 1;
    }
};
