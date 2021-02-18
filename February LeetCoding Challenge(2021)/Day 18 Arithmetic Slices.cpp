class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        
        vector<int> dp(n); // number of slices ending at i
        int res = 0;
        
        if (A[2]-A[1] == A[1]-A[0]) dp[2] = 1;
        res += dp[2];
        
        for(int i=3; i<n; i++){
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) dp[i] = dp[i-1] + 1;
            res += dp[i];
        }
        return res;
    }
};

// O(1) dp, @thx2kevin
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		if(n <= 2) return 0;
		int dp=0;
		
		int res = 0;
		for(int i=2; i<n; ++i){
			if(A[i]-A[i-1] == A[i-1]-A[i-2])
				++dp;
			else
				dp=0;
			res += dp;
		}
		
		return res;
	}
};
