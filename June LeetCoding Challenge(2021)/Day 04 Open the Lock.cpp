class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> blocked(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        
        if (blocked.count("0000")) return -1;
        q.push("0000");
        visited.insert("0000");
        
        int res = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto cur = q.front(); q.pop();
                auto next = neighbour(cur);
                if (cur == target) return res;
                for(auto n : next){
                    if (visited.count(n)) continue;
                    if (!blocked.count(n)){
                        visited.insert(n);
                        q.push(n);
                    }
                }
            }
            res++;
        }
        return -1;
        
    }
    
    vector<string> neighbour(string s){
        vector<string> res;
        
        for(int i=0; i<4; i++){
            string temp = s;
            temp[i] = (s[i] - '0' + 1) % 10 + '0';
            res.push_back(temp);
            temp[i] = (s[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(temp);
        }
        
        return res;
    }
};
