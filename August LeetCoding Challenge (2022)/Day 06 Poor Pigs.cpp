class Solution {
public:
    /*
    Let T = num test
    N = bucket
    x = pig
    
    Find (T+1)^x >= N
    
    Why T+1 instead of T?
    @https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution
    
    With 2 pigs, poison killing in 15 minutes, and having 60 minutes, we can find the poison in up to 25 buckets in the following way. Arrange the buckets in a 5×5 square:

 1  2  3  4  5
 6  7  8  9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

Now use one pig to find the row (make it drink from buckets 1, 2, 3, 4, 5, wait 15 minutes, make it drink from buckets 6, 7, 8, 9, 10, wait 15 minutes, etc). Use the second pig to find the column (make it drink 1, 6, 11, 16, 21, then 2, 7, 12, 17, 22, etc).

Having 60 minutes and tests taking 15 minutes means we can run four tests. If the row pig dies in the third test, the poison is in the third row. If the column pig doesn't die at all, the poison is in the fifth column (this is why we can cover five rows/columns even though we can only run four tests).
    
    
    Now, why (T+1)^x >= N, instead of x^(T+1) >= N
    Use x = 1 for example,
    if T = 4, we can test 5 buckets if use the first formula, which is correct
    if second formula, we can test 1^4 = 1 bucket, which is wrong
    
    
    */
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int trials = minutesToTest / minutesToDie;
        while(pow(trials+1, pigs) < buckets){
            pigs++;
        }
        return pigs;
    }
};
