/*
Idea:
Let say matrix = 
1 2 3
4 5 6
7 8 9

2 and 4 will having the same sum of i j, eg: 2 = matrix[0][1], 4 = matrix[1][0].
Check all sum and push them into a map.
At the last just reverse those with even sum.

*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        
        int m = matrix.size(), n = matrix[0].size();
        
        map<int, vector<int>> mp; // sum of index, num
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[i+j].push_back(matrix[i][j]);
            }
        }
        for(auto& x : mp){
            if (x.first % 2 != 0){ // no need reverse
                for(int& num : x.second) res.push_back(num);
            }else{ // need reverse
                for(int i=x.second.size()-1; i>=0; i--) res.push_back(x.second[i]);
            }
        }
        return res;
    }
};
