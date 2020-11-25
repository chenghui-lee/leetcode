class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1; // 2 will get 2,4,6,8 while 5 will get 0 or 5, so its impossible
        int remainder = 0;
        
        // other than that, for any number, there always exist a result
        for(int n=1; n<=K; n++){ // there are at most K remainder, 0, 1, 2, ... K-1
            remainder = (remainder*10 + 1)%K; // we cant store N directly because the number can be very large
            if (remainder == 0) return n;
        }
        return -1;
    }
};
