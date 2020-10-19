class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if (A.size() != B.size() || A.size() == 0) return 0;
        
        vector<int> a(7), b(7), same(7);
        for(int i=0; i<A.size(); i++){
            a[A[i]]++;
            b[B[i]]++;
            if (A[i] == B[i]) same[A[i]]++;
        }
        for(int i=1; i<=6; i++){
            if (a[i] + b[i] - same[i] == A.size()){
                return A.size() - max(a[i], b[i]);
            }
        }
        return -1;
    }
};
