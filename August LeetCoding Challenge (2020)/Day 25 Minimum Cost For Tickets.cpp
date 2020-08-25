class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> s;
        for(auto x : days) s.insert(x);
        vector<int> cost(366); // 0 - 365
        
        for(int i=1; i<366; i++){
            if(s.find(i) == s.end()){ // if not travel day
                cost[i] = cost[i-1];
            }else{
                cost[i] = min({cost[i-1] + costs[0], cost[max(i-7, 0)] + costs[1], cost[max(i-30, 0)] + costs[2]});
            }
        }
        return cost[365];
    }
};
