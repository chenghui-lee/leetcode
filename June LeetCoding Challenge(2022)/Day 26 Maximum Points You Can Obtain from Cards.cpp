class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (k == n) return sum;
        
        int middle = n - k;
        int middleSum = 0, res = 0;
        for(int i=0; i<middle; i++){
            middleSum += cardPoints[i];
        }
        res = max(res, sum - middleSum);
        for(int j=1; j+middle-1<n; j++){
            middleSum -= cardPoints[j-1];
            middleSum += cardPoints[j+middle-1];
            res = max(res, sum - middleSum);
        }
        return res;
        
    }
};
