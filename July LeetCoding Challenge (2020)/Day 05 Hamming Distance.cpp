class Solution {
public:
    int hammingDistance(unsigned int x, unsigned int y) {
    
        // this method below shld be working, but for some reason it don't, we XOR both num and then count number of 1 inside
        // int res = 0;
        // unsigned int k = x^y;
        // while(k>0){
        //     if(k&1) res++;
        //     k >> 1;
        // }
        // return res;
        return __builtin_popcount(x ^ y);
    }
};
 
// another method
int n = x^y;
private int countOne(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
}
