class WordDictionary {
private:
    struct Trie{
        bool isWord;
        vector<Trie*> children;
        Trie(): isWord(false), children(vector<Trie*>(26, nullptr)){};
        
        void add(string word){
            Trie* cur = this;
            for(int i=0; i<word.size(); i++){
                if (cur->children[word[i] - 'a'] == nullptr){
                    cur->children[word[i] - 'a'] = new Trie();
                }
                cur = cur->children[word[i] - 'a'];
            }
            cur->isWord = true;
        }
        
        bool search(Trie* root, string word, int index){
            if (index == word.size()){
                return root->isWord;
            }
            if (word[index] == '.'){
                for(int i=0; i<root->children.size(); i++){
                    if (root->children[i] != nullptr && search(root->children[i], word, index+1)){
                        return true;
                    }
                }
            }else{
                return root->children[word[index] - 'a'] != nullptr && search(root->children[word[index] - 'a'], word, index+1);
            }
            return false;
        }
        
    };
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        root->add(word);
    }
    
    bool search(string word) {
        return root->search(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
