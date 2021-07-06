class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto x : arr) m[x]++;
        priority_queue<int> q;
        
        for(auto p : m) q.push(p.second);
        int res = 0, cur = 0;
        
        while(cur < arr.size() / 2){
            res++;
            cur += q.top(); q.pop();
        }
        return res;
    }
};
