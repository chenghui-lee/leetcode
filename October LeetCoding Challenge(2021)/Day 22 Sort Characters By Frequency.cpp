class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        string res = "";
        for (char x : s){
            m[x]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto x : m){
            pq.push({x.second, x.first});
        }
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int t = x.first;
            while(t--){
                res += x.second;
            }
        }
        return res;
    }
};
