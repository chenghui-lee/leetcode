// https://leetcode.com/problems/regular-expression-matching/discuss/5651/Easy-DP-Java-Solution-with-detailed-Explanation/238767
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false)); // dp[i][j] = first i-th char in s match with first j-th char in p
        dp[0][0] = true; // when both string empty, true
        // dp[i][0] = false, cant match empty pattern with string
        // dp[0][j] = true if pattern = ?*?*?*
      
        for(int j=2; j<=n; j++){
            if (p[j-1] == '*' && dp[0][j-2]){
                dp[0][j] = true;
            }
        }
        /*
        // Induction rule is very similar to edit distance, where we also consider from the end. And it is based on what character in the pattern we meet.
        // 1. if p.charAt(j) == s.charAt(i), M[i][j] = M[i - 1][j - 1]
		//    ######a(i)
		//    ####a(j)
        // 2. if p.charAt(j) == '.', M[i][j] = M[i - 1][j - 1]
        // 	  #######a(i)
        //    ####.(j)
        // 3. if p.charAt(j) == '*':
        //    1. if p.charAt(j - 1) != '.' && p.charAt(j - 1) != s.charAt(i), then b* is counted as empty. M[i][j] = M[i][j - 2]
        //       #####a(i)
        //       ####b*(j)
        //    2.if p.charAt(j - 1) == '.' || p.charAt(j - 1) == s.charAt(i):
        //       ######a(i)
        //       ####.*(j)
		//
		// 	  	 #####a(i)
        //    	 ###a*(j)
        //      2.1 if p.charAt(j - 1) is counted as empty, then M[i][j] = M[i][j - 2]
        //      2.2 if counted as one, then M[i][j] = M[i - 1][j - 2]
        //      2.3 if counted as multiple, then M[i][j] = M[i - 1][j]
        
        
        */
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                char curS = s[i-1];
                char curP = p[j-1];
                if (curS == curP || curP == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if (curP == '*'){
                    char prevP = p[j-2];
                    if (prevP != '.' && prevP != curS){
                        dp[i][j] = dp[i][j-2]; // ignore the current #*
                    }else{
                        dp[i][j] = (dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j]);
                        // ignore, count as one, count as many
                    }
                }
            }
        }
        return dp[m][n];
    }
};
