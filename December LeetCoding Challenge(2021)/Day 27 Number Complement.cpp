class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;
        int numofbits = log2(num) + 1;
        int maxx = pow(2, numofbits)-1;
        return num^maxx;
    }
};
