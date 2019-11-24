public static int longestCommonSubsequence(String text1, String text2) {
        if (text1 == null || text1.length() == 0 || text2 == null || text2.length() == 0) {

            return 0;

        }

        // Solve using dynamic programming
        int m = text1.length();

        int n = text2.length();

        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {
                if (text1.charAt(i) == text2.charAt(j)) {
                    dp[i + 1][j + 1] = Math.max(dp[i + 1][j + 1], dp[i][j] + 1); //其实这里不用max也可以，直接拿dp[i][j] +1 (diagonal +1)
                } else {
                    dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]); // 拿左边和上面的max
                }
            }
        }
        return dp[m][n];
    }
