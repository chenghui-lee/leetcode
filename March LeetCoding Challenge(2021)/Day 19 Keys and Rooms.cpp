class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> unlocked(n);
        vector<bool> processed(n);
        
        queue<int> q;
        q.push(0);
        unlocked[0] = 1;
        processed[0] = 1;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto cur = q.front();
                q.pop();
                for(auto next : rooms[cur]){
                    if (! processed[next]){
                        q.push(next);
                        unlocked[next] = 1;
                    }
                }
                processed[cur] = 1;
            }
        }
        for(int i=0; i<n; i++){
            if (!unlocked[i]) return false;
        }
        return true;
    }
};
