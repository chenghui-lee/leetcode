/*
Idea:
Generate all prefix and suffix for all word, combine and store inside map

*/
class WordFilter {
public:
    unordered_map<string, int> m; // prefix#suffix, index
    
    WordFilter(vector<string>& words) {
        
        for(int idx=0; idx<words.size(); idx++){
            string w = words[idx];
            for(int prefixLen=1; prefixLen<=w.size(); prefixLen++){
                for(int suffixLen=1; suffixLen<=w.size(); suffixLen++){
                    string temp = w.substr(0, prefixLen) + "#" + w.substr(w.size() - suffixLen);
                    m[temp] = idx;
                }
            }
                
        }
    }
    
    int f(string prefix, string suffix) {
        string temp = prefix + "#" + suffix;
        if (m.find(temp) == m.end()) return -1;
        return m[temp];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
