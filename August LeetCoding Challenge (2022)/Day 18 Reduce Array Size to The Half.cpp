class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int x : arr){
            count[x]++;
        }
        priority_queue<int> pq;
        for(auto p : count) pq.push(p.second);
        int n = arr.size();
        int curSize = 0;
        int res = 0;
        
        while(curSize < n / 2){
            curSize += pq.top();
            res++;
            pq.pop();
        }
        
        return res;
    }
};
