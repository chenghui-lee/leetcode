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
// another solution
string frequencySort(string s) {
        int count[256] = {0};
        for(char c : s)
            count[c] += 1;
        vector<pair<int,char>> arr;
        for(int c = 0; c < 256; ++c) // 256 bcs ascii got 256 characters
        {
            if(count[c]) arr.push_back({count[c],c});
        }
        sort(arr.rbegin(), arr.rend()); // reverse, from big to small
        string res;
        for(auto p : arr)
        {
            res += string(p.first, p.second);
        }
        return res;
    }
