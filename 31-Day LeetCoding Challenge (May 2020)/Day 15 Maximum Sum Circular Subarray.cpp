//https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
//https://www.youtube.com/watch?v=UcRham8J5rI
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxCur = 0, maxGlo = INT_MIN;
        int minCur = 0, minGlo = INT_MAX;
        for (int i = 0; i<A.size(); i++){
            maxCur = max(maxCur+A[i], A[i]);
            maxGlo = max(maxGlo, maxCur);
            
            minCur = min(minCur+A[i], A[i]);
            minGlo = min(minGlo, minCur);
        }
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum==minGlo) return maxGlo;
        else return max(maxGlo, sum-minGlo);
    }
};
