class Solution {
public:
    int smallestEvenMultiple(int n) {
        int t = n;
        while(t % 2 != 0){
            t+=n;
        }
        return t;
    }
};