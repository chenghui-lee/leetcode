class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if (A.size() == 0 || B.size() == 0) return res;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()){
            if (A[i][0] >= B[j][0] && A[i][0] <= B[j][1] || B[j][0] >= A[i][0] && B[j][0] <= A[i][1]){
                res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            }
            if (A[i][1] < B[j][1]) i++;
            else j++;
        }
        return res;
    }
};
// to check for intersect, if starting point lies btwn start & end of another, yes
// to get range, pick later starting point and earlier ending point
