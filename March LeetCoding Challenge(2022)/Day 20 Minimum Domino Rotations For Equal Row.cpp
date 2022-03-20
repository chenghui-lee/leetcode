class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        if (tops.size() == 0) return -1;
        
        vector<int> a(7, 0), b(7, 0), same(7, 0);
        for(int i=0; i<tops.size(); i++){
            a[tops[i]]++;
            b[bottoms[i]]++;
            if (tops[i] == bottoms[i]) same[tops[i]]++;
        }
        for(int i=1; i<=6; i++){
            if (a[i] + b[i] - same[i] == tops.size()){
                return tops.size() - max(a[i], b[i]);
            }
        }
        return -1;
    }
};
