// https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42198/My-solution-does-not-need-a-table-for-palindrome-is-it-right-It-uses-only-O(n)-space./121715
/*
dp[i] = num cuts to make s[0..i] palindrome
Note that we start expanding on each char as middle.

if the left is 0, and s[left] == s[right], dp[right] = 0
this is because, we no need any more cuts before the starting position.

else we will pick the min between the current best cut / dp[start-1] + 1 (cut before starting position + 1)
*/

class Solution {
public:
    void search(string& s, vector<int>& dp, int start, int end){
        while(start >= 0 && end < s.size() && s[start] == s[end]){
            if (start == 0){ // no need to have a cut before this string
                dp[end] = 0;
            }else{
                dp[end] = min(dp[end], dp[start-1] + 1); // having a cut before the starting
            }
            start--, end++;
        }
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n);
        
        for(int i=0; i<n; i++){
            dp[i] = i;
        }
        
        for(int i=0; i<n; i++){
            search(s, dp, i, i);
            search(s, dp, i, i+1);
        }
        return dp[n-1];
    }
};
