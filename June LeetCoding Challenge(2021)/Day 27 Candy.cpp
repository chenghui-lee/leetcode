// greedy, n logn
class Solution {
public:
    typedef pair<int,int> pi;
    int candy(vector<int>& ratings) {
        priority_queue<pi, vector<pi>, greater<pi>> pq; // min heap
        
        for(int i=0; i<ratings.size(); i++){
            pq.push(make_pair(ratings[i], i));
        }
        vector<int> res(ratings.size(), 1);
        while(!pq.empty()){
            auto [cur, idx] = pq.top(); pq.pop();
            if (idx-1 >=0 && ratings[idx-1] < cur){
                res[idx] = res[idx-1] + 1;
            }
            if (idx+1 <ratings.size() && ratings[idx+1] < cur){
                res[idx] = max(res[idx], res[idx+1] + 1);
            }
        }
        
        return accumulate(res.begin(), res.end(), 0);
    }
};
