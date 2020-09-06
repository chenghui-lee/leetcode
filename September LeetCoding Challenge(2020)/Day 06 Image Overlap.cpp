class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<pair<int, int>> a, b; // to store all the locations of 1s in both square
        
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A[0].size(); j++){
                if(A[i][j] == 1) a.push_back({i,j});
                if(B[i][j] == 1) b.push_back({i,j});
            }
        }
        unordered_map<string, int> vectors; // map vector(string) to count
        for(auto pa : a){
            for(auto pb : b){
                string vec = to_string(pa.first - pb.first) + " " + to_string(pa.second - pb.second); // find the vector using 2 points
                vectors[vec] ++;
            }
        }
        
        int res = 0;
        for(auto x : vectors){
            res = max(res, x.second);
        }
        return res;
    }
};
