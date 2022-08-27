class Solution {
public:
    /*
    Basic idea:
    
    Maintain one array of sum, containing the sum of element in all of the rows
    | |
    | |
    | |
    | |  not |_|_|_|_|_|
    
    Then use 2 variable left, right to use a "sliding window" for the cols
    left = 0 -> max_col
    right = left -> max_col
    
    The sum of the rectangle is flatten into that sum array
    
    The next job is to find the max subarray which is smaller than k
    
    */
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int res = INT_MIN;
        
        for(int left=0; left<n; left++){
            vector<int> sum(m, 0);
            for(int right=left; right<n; right++){
                for(int i=0; i<m; i++){
                    sum[i] += matrix[i][right];
                }
                
                // max subarray which is smaller than k
                // https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
                set<int> accu;
                accu.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for(int x : sum){
                    curSum += x;
                    auto it = accu.lower_bound(curSum - k);
                    if (it != accu.end()) curMax = max(curMax, curSum - *it);
                    accu.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};
