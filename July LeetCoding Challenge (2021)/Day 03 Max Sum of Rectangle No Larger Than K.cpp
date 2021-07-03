// https://www.youtube.com/watch?v=yCQN096CwWM
// https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int res = INT_MIN;
        
        for(int l=0; l<col; l++){
            vector<int> sum(row, 0);
            for(int r=l; r<col; r++){
                
                for(int i=0; i<row; i++){
                    sum[i] += matrix[i][r];
                }
                // find max subarray not more than k
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
