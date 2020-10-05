// find the first 1111.11 num that is larger than N,
// then use that num to minus N.

class Solution {
public:
    int bitwiseComplement(int N) {
        int x = 1;
        while(N>x){
            x = x*2 + 1;
        }
        return x-N;
    }
};
