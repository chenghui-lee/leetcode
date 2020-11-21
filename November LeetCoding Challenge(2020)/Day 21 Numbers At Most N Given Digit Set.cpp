class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int k = s.length(), d = digits.size();
        
        int res = 0;
        for(int i=1; i<k; i++){ // all possible combination where num of digit is less than num of digit of n
            res += pow(d, i);
        }
        
        for(int i=0; i<k; i++){
            bool needToCheckNext = false;            
            for(auto& x : digits){
                if (x[0] < s[i]){
                    res += pow(d, k - i - 1); // 1xxxx for 52525
                }else if (x[0] == s[i]){
                    needToCheckNext = true; // need to check for the next digit of num
                    break; // because the remaining digit from digits are confirm to be larger than s[i]
                }
            }
            if (!needToCheckNext) return res;
        }
        return res + 1; // + 1 because of itself.
    }
};
