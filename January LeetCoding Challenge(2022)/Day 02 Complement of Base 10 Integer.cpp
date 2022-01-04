class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int tmp = log2(n)+1;
        return n ^ ((1 << tmp) - 1);
    }
};
