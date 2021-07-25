// https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/discuss/103749/Java-Solution-DP/116136

class Solution {
public:
    int findIntegers(int num) {
        vector<int> bits;
        for(int cur = num; cur>0; cur >>= 1){
            bits.push_back(cur & 1);
        }
        
        int n = bits.size();
        vector<int> zero(n), one(n); 
        /*
         zero[i] be the number of binary strings of length i which do not contain any two 
         consecutive 1’s and which end in 0. 
         Similarly, let one[i] be the number of such strings which end in 1
         
         We can append either 0 or 1 to a string ending in 0, 
         but we can only append 0 to a string ending in 1.
         */
        zero[0] = one[0] = 1;
        for(int i=1; i<n; i++){
            one[i] = zero[i-1];
            zero[i] = one[i-1] + zero[i-1];
        }
        int res = zero[n-1] + one[n-1];
        
        // now need to remove those number having the 
        // same length of bit, but larger than num
        
        for(int i=n-2; i>=0; i--){
            if (bits[i] == 0 && bits[i+1] == 0) res -= one[i];
            else if (bits[i] == 1 && bits[i+1] == 1) break; // consecutive one, res doesnt include
        }
        return res;
    }
};
