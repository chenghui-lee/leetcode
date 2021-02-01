// Solution 1, 8ms
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            if (n%2) count++;
            n /= 2;
        }
        return count;
    }
};

// Solution 2, 0ms
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count++;
            n &= (n-1);
        }
        return count;
    }
};
