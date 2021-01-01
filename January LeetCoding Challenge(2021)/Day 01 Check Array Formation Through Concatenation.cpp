class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int count = 0, n = arr.size();
        unordered_map<int, int> pos;
        
        for(int i=0; i<n; i++){
            pos[arr[i]] = i;
        }
        
        for(int i =0; i<pieces.size(); i++){
            if (!pos.count(pieces[i][0])) return false;
            int ini = pos[pieces[i][0]];
            count++;
            for(int j=1; j<pieces[i].size(); j++){
                if (!pos.count(pieces[i][j]) || ini + j != pos[pieces[i][j]]) return false;
                count++;
            }
        }
        return count == n;
    }
};
