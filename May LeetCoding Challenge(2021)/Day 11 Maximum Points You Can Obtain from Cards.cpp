// Take k cards on the right, then start from the first one on left side, removing the rightside.
/* 1 2 [3 5 6]
   1]2 3  [5 6
   1 2]3  5 [6
   [1 2 3] 5 6

*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), res = 0;
        for(int i=n-k; i<n; i++){
            res += cardPoints[i];
        }
        for(int i=0, temp=res; i<k; i++){
            temp -= cardPoints[n-k+i];
            temp += cardPoints[i];
            res = max(res, temp);
        }
        return res;
    }
};
