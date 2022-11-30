class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        unordered_set<int> s;
        for(int x : arr) count[x]++;
        for(auto p : count){
            if (s.find(p.second) != s.end()) return false;
            s.insert(p.second);
        }
        return true;
    }
};
