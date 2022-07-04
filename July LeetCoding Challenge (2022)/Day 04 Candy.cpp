/*
Greedy, assign candy for lower rating 1st

*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        // min heap, <rating, index>
        int n = ratings.size();
        for(int i=0; i<n; i++){
            pq.push({ratings[i], i});
        }
        
        vector<int> res(n, 1);
        while(!pq.empty()){
            auto [curRating, idx] = pq.top(); pq.pop();
            // check left side
            if (idx-1>=0 && ratings[idx-1] < curRating){
                res[idx] = res[idx-1] + 1;
            }
            // check right side
            if (idx+1<n && ratings[idx+1] < curRating){
                res[idx] = max(res[idx], res[idx+1] + 1);
            }
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};
