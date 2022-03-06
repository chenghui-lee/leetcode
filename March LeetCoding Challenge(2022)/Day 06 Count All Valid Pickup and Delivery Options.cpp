class Solution {
public:
    /*
    @lee215
    Assume we have already n - 1 pairs, now we need to insert the nth pair.
    To insert the first element, there are n * 2 - 1 chioces of position。
    To insert the second element, there are n * 2 chioces of position。
    So there are (n * 2 - 1) * n * 2 permutations.
    Considering that delivery(i) is always after of pickup(i), we need to divide 2.
    So it's (n * 2 - 1) * n.
    
    */
    int countOrders(int n) {
        long long res = 1, MOD = 1e9 + 7;
        for(int i=1; i<=n; i++){
            res = res * (i * 2 - 1) * i % MOD;
        }
        return (int)res;
    }
};
