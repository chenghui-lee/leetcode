class Solution {
public:
    //https://stackoverflow.com/questions/1804311/how-to-check-if-an-integer-is-a-power-of-3
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
        
        // this magic number is the maximum power 3 that can fit into signed 32 bit integer
    }
};
