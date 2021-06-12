class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
        int cur = startFuel;
        
        int res = 0;
        for(auto s : stations){
            if (s[0] > cur){
                while(!q.empty() && cur < s[0]){
                    cur += q.top();
                    q.pop();
                    res++;
                }
                if (cur < s[0]) return -1;
            }
            q.push(s[1]);
        }
        while(!q.empty() && cur < target){
            cur += q.top();
            q.pop();
            res++;
        }
        return cur>=target?res:-1;
    }
};
