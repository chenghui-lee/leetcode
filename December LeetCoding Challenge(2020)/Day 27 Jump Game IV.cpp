class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        else if (arr[0] == arr[n-1]) return 1;
        
        unordered_map<int, vector<int>> pos;        
        
        // building pos of same number
        for(int i=0; i<n; i++){
            pos[arr[i]].push_back(i);
        }

        
        queue<int> q;
        vector<bool> visited(n);
        q.push(0);
        visited[0] = 1;
        int res = 0;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int cur = q.front(); q.pop();
                if (cur == n-1) return res;
                
                vector<int> &next = pos[arr[cur]];
                next.push_back(cur-1), next.push_back(cur+1);
                for(auto& nx : next){
                    if (nx >=0 && nx < n && !visited[nx]){
                        visited[nx] = 1;
                        q.push(nx);
                    }
                }
                next.clear();
            }
            res++;
        }
        
        
        return -1;
        
    }
};
