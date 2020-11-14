// (T+1)^x >= n

/* 
   T = total time / poison time
   x = num of pigs
   n = number of buckets
*/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int trials = minutesToTest / minutesToDie;
        while(pow(trials+1, pigs) < buckets){
            pigs += 1;
        }
        return pigs;
    }
};
