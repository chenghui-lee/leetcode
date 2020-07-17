class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size()==0) return res;
        
        unordered_map<int, int> frequency; // element, frequency
        int max_frequency = 0;
        for (auto x : nums){
            frequency[x]++;
            max_frequency = max(max_frequency, frequency[x]);
        }
        
        unordered_map<int, vector<int>> table; // frequency, list of element
        for(auto x : frequency){
            table[x.second].push_back(x.first);
        }
        
        for(int i = max_frequency; i>=1; i--){
            auto it = table.find(i);
            if (it == table.end()) continue; // if that frequency has no element, skip
            res.insert(res.end(), it->second.begin(), it->second.end()); // insert all of the elements with the same frequency
            if (res.size() >= k) return res;
        }
        return res;
    }
};
