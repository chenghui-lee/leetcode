// suppose we have a number like 5(dec) = 101(bin), no leading zero
// we obtain the number of bits by log2(5)+1 = 3
// we find the number where all of the bits is one, this case is 111 -> 7
// we XOR both of them to get 010 or 2(dec)
/*
    101     5(dec)
xor 111     7(dec)
=   010     2(dec)
*/
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

// here is another solution ,using the same concept: 
// we use while loop to find the max number by left shifting it and + 1
// example:
/*
initially mask =1
-> 11
-> 111
-> 1111
and so on
at last we xor the number with the mask
*/
int findComplement(int num) {
        int mask = 1;
        
        while(mask < num) {
            mask = (mask << 1) + 1;
        }
        
        return num ^ mask;
    }
