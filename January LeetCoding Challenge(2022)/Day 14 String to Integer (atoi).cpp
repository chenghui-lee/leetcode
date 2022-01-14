// https://leetcode.com/problems/string-to-integer-atoi/discuss/4654/My-simple-solution/5475
class Solution {
public:
        int myAtoi(string str) {
            int sign = 1, pt = 0; 
            long long base = 0;
            while (str[pt] == ' ')
                pt++;
            if (str[pt] == '+' || str[pt] == '-')
                sign = 1 - 2 * (str[pt++] == '-');
            while (str[pt] >= '0' && str[pt] <= '9') {
                base = 10 * base + (str[pt++] - '0');
                if (base > INT_MAX)
                    return sign == 1 ? INT_MAX : INT_MIN;
            }
            return (int) (base * sign);
    }
};
