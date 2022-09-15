class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 == 1) return {};
        
        unordered_map<int, int> m;
        for(int x : changed) m[x]++;

        vector<int> unique;
        for(auto x : m) unique.push_back(x.first);
        sort(unique.begin(), unique.end());
        
        vector<int> res;
        for(int x : unique){
            if (m[x] > m[x*2]) return {};
            for (int i = 0; i < m[x]; ++i, m[2 * x]--)
                res.push_back(x);
        }
        return res;
    }
};
