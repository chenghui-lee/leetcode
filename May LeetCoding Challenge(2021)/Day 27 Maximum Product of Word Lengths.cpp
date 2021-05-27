class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        unordered_map<string ,int> m; // string, hash
        
        for(auto& w : words){
            for(auto ch : w){
                m[w] |= 1 << (ch - 'a');
            }
        }
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if ((m[words[i]] & m[words[j]]) == 0){
                    res = max(res, (int) (words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};
