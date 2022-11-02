class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        unordered_set<string> valid;
        for(string s : bank) valid.insert(s);
        if (valid.find(end) == valid.end()) return -1;
        vector<char> moves = {'A', 'C', 'G', 'T'};
        valid.erase(start);
        queue<string> q;
        q.push(start);
        
        int res = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto cur = q.front(); q.pop();
                if (cur == end) return res;
                for(int i=0; i<cur.size(); i++){
                    char ori = cur[i];
                    for(int j=0; j<moves.size(); j++){
                        if (ori == moves[j]) continue;
                        cur[i] = moves[j];
                        if (valid.find(cur) == valid.end()) continue;
                        valid.erase(cur);
                        q.push(cur);
                    }
                    cur[i] = ori;
                }
            }
            res++;
        }
        return -1;


    }
};
