class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <num, idx>
        for(int i=0; i<mat.size(); i++){
            int count = 0;
            for(int j=0; j<mat[i].size(); j++){
                if (mat[i][j] == 0) break;
                count++;
            }
            pq.push({count, i});
        }
        vector<int> res;
        while(k--){
            auto cur = pq.top(); pq.pop();
            res.push_back(cur.second);
        }
        return res;
    }
};
// with binary search to find the 1 location
class Solution {
public:
    int numOnes(vector<int> v){
        int low = 0, high = v.size(); // here v.size() instead of v.size()-1
        while(low < high){
            int mid = (low + high) / 2;
            if (v[mid] == 1) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <num, idx>
        for(int i=0; i<mat.size(); i++){
            pq.push({numOnes(mat[i]), i});
        }
        vector<int> res;
        while(k--){
            auto cur = pq.top(); pq.pop();
            res.push_back(cur.second);
        }
        return res;
    }
};
