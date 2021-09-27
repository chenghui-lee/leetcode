class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0, res = 0, n = events.size();
        for(int d=1; d<=100000; d++){
            while(!pq.empty() && pq.top() < d) { // remove expired event
                pq.pop();
            }
            while(i < n && events[i][0] == d){
                pq.push(events[i++][1]);
            }
            if (pq.size() > 0) { // attend an event, (pick the earliest end date)
                res++;
                pq.pop();
            }
            
        }
        return res;
    }
};
