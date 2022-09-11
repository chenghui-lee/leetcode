class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,double>> arr;
        for(int i=0; i<quality.size(); i++){
            arr.push_back({(double) wage[i] / (double) quality[i], quality[i]});
        }
        sort(arr.begin(), arr.end()); 
        // sort the worker by increasing ratio
        // cheaper to more expensive
        /*
         
        Then use a priority queue to keep track of the current workers
        We can satisfy all the wage if we use the current ratio to pay everyone(since we sort increasingly)
        If > k workers, remove the one with the highest quality (save cost)
        */
        
        priority_queue<int> pq; // max heap
        double res = INT_MAX;
        int sumQuality = 0;
        for(auto worker : arr){
            if (pq.size() < k-1){ // can hire directly
                sumQuality += worker.second;
                pq.push(worker.second);
            } else { // enuf people after hiring this one
                sumQuality += worker.second;
                pq.push(worker.second);
                res = min(res, sumQuality * worker.first);
                // then remove 1 people to prepare for the next worker
                sumQuality -= pq.top(); pq.pop();
            }
        }
        return res;
    }
};
