class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        
        int res = A[n-1] - A[0];
        
        for(int i=0; i<n-1; i++){
            int upper = max(A[n-1] - K, A[i] + K);
            int lower = min(A[0] + K, A[i+1] - K);
            res = min(res, upper - lower);
        }
        return res;
    }
};
