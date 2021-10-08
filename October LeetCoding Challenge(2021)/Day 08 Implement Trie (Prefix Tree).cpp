class Trie {
public:
    struct Trie_{
        bool isWord;
        vector<Trie_*> child;
        Trie_(): child(vector<Trie_*>(26, nullptr)), isWord(false){}
    };
    
    Trie_* root;
    Trie() {
        root = new Trie_();
    }
    
    void insert(string word) {
        Trie_* cur = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';
            if (cur->child[idx] == nullptr){
                cur->child[idx] = new Trie_();
            }
            cur = cur->child[idx];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        Trie_* cur = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';
            if (cur->child[idx] == nullptr) return false;
            cur = cur->child[idx];
        }
        
        return cur && cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie_* cur = root;
        for(int i=0; i<prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if (cur->child[idx] == nullptr) return false;
            cur = cur->child[idx];
        }
        if (cur->isWord) return true;
        for(auto child : cur->child){
            if (child) return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
