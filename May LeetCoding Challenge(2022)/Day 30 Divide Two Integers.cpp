class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        long num = labs(dividend), div = labs(divisor);
        long res = 0;
        
        while(num >= div){
            long divCopy = div, multiple = 1;
            while(num >= divCopy << 1){ // to ensure not exceeding the num
                divCopy <<= 1;
                multiple <<= 1;
            }
            num -= divCopy;
            res += multiple;
        }
        
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        return res * sign;
    }
};
