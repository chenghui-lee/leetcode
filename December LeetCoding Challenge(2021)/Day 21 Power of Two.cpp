class Solution {
public:
    bool isPowerOfTwo(int n) {
        return __builtin_popcountl(n) == 1;
    }
};
/*
__builtin_popcount(n) = int
__builtin_popcountl(n) = long
__builtin_popcountll(n) = long long

in this question, got -2^31, so to be safe, use long

*/
