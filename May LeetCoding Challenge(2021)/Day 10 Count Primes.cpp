// Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        for(int i=2; i*i < n; i++){
            for(int j=i; i*j <n; j++){
                prime[i*j] = 0;
            }
        }
        int res = 0;
        for(int i=2; i<n; i++) res += prime[i];
        return res;
    }
};
