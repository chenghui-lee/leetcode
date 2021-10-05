// top down
// O(nk) time and space
// n = length of string, k = at most k type character
class Solution {
public:
    map<pair<int, int>, int> seen;
    int help(int n, int k){
        if (n == 1 || k == 1){
            return k;
        }
        if (seen.find({n, k}) != seen.end()){
            return seen[{n,k}];
        }
        int sum = 0;
        for(int i=1; i<=k; i++){
            sum += help(n-1, i);
        }
        return seen[{n, k}] = sum;
    }
    
    int countVowelStrings(int n) {
        return help(n, 5);
    }
};

// bottom up
// O(nk) time and space
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(6, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=5; j++){
                dp[i][j] = dp[i][j-1] + (i > 1? dp[i-1][j] : 1);
            }
        }
        return dp[n][5];
    }
};

// bottom up
// O(nk) time, O(k) space
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp = {0, 1, 1, 1, 1, 1};
        for(int i=1; i<=n; i++){
            for(int j=1; j<=5; j++){
                dp[j] += dp[j-1];
            }
        }
        return dp[5];
    }
};

// O(1) time and space
// we need to put 4 delimiters (because we have 5 vowels)in n+4 spaces
// so it is n+4 C 4
// a | e | i | o | u
// xxx|xxx|xx|x|x -> n+4 C 4

class Solution:
    def countVowelStrings(self, n: int) -> int:
        return comb(n+4, 4)
