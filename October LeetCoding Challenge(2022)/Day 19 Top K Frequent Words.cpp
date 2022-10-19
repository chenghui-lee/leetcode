class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> count; // word, fre
        for(string w : words) count[w]++;

        map<int, vector<string>> countToWord; // count, [list of word having this count]
        for(auto p : count){
            countToWord[p.second].push_back(p.first);
        }
        auto it = countToWord.rbegin();
        int cur = 0;
        while(cur < k){
            sort(begin(it->second), end(it->second));
            for(int i=0; i<it->second.size() && cur < k; i++, cur++){
                res.push_back(it->second[i]);
            }
            it++;
        }
        return res;
    }
};
