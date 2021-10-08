class MagicDictionary {
public:
    unordered_set<string> s;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i=0; i<dictionary.size(); i++){
            s.insert(dictionary[i]);
        }
    }
    
    bool search(string searchWord) {
        for(int i=0; i<searchWord.size(); i++){
            for(char c = 'a'; c<='z'; c++){
                if (c == searchWord[i]) continue;
                char temp = searchWord[i];
                searchWord[i] = c;
                if (s.find(searchWord) != s.end()) return true;
                searchWord[i] = temp;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

// use map<len, string>
class MagicDictionary {
public:
    map<int, vector<string>> m;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i=0; i<dictionary.size(); i++){
            m[dictionary[i].size()].push_back(dictionary[i]);
        }
    }
    
    bool search(string searchWord) {
        for(const string s : m[searchWord.size()]){
            int diff = 0;
            for(int i=0; i<searchWord.size(); i++){
                diff += (searchWord[i] != s[i]);
            }
            if (diff == 1) return true;
        }
        return false;
    }
};
