// at first, I loop through all the integer in the range, but this way is not efficient and result and tle
// hence we have to use other methods like bit manipulation

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m==n){
            return m;
        }
        if (m == 0 || n ==0){
            return 0;
        }
        while (m < n){
            n -= (n & -n);
            if (n==m)
                return n;
        }
        return n;
    }
};

// here is another solution from : https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/592288/100-memory!-C%2B%2B-solution-with-explanation
// let's consider the example [5,7]
// 5 : 0101
// 6 : 0110
// 7 : 0111
// we need to find the position(count) at which all the numbers are having 1 on that position. Because 0 and 1 will give 0 in AND operation.
// we right shift both numbers(m,n) to find the position
// when we get the position, we shift left back m to get the final result

int rangeBitwiseAnd(int m, int n) {
        int count=0;
        while(m!=n)  // see till both numbers are equal
        {   // right shift both numbers by 1
            m>>=1; 
            n>>=1;
            count++;  // increment the count.
        }
		//count gives the number of zero places from the lsb so left shift m by count.
        return m<<count;
    }
