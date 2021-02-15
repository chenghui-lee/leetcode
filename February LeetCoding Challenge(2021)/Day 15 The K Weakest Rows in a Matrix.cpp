class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        
        for(int i=0; i<mat.size(); i++){
            int num = 0;
            for(auto human : mat[i]) num += human;
            v.push_back({num, i});
        }
        sort(v.begin(), v.end());
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(v[i].second);
        }
        return res;
    }
};
