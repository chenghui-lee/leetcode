class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r*c != mat.size() * mat[0].size()) return mat;
        queue<int> q;
        for(auto row:mat){
            for(auto x:row) q.push(x);
        }
        vector<vector<int>> res(r, vector<int>(c));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                auto x = q.front(); q.pop();
                res[i][j] = x;
            }
        }
        return res;
    }
};
