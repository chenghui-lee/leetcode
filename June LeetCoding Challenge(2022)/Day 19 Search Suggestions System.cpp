class Solution {
public:
    
    class Trie{
    public:
        bool isWord;
        Trie* children[26];
        set<string> wordsHavingThisPrefix;
        
        Trie(){
            isWord = false;
            for(int i=0;i<26;i++){
                this->children[i] = NULL;
            }
        }
        
        void insert(string word) {
            Trie* root = this;
            for(int i=0; i<word.size(); i++){
                int index = word[i] - 'a';
                if (root->children[index] == NULL){
                    root->children[index] = new Trie();                    
                }
                root = root->children[index];
                root->wordsHavingThisPrefix.insert(word);
            }
            root->isWord = true;
        }
        
        vector<vector<string>> find(string prefix){
            vector<vector<string>> res;
            Trie* root = this;
            int i = 0;
            for(; i<prefix.size() && root; i++){
                int index = prefix[i] - 'a';
                if (root->children[index] == NULL){
                    break;
                }
                root = root->children[index];
                auto it = root->wordsHavingThisPrefix.begin();
                vector<string> temp;
                for(int j=0; j<3 && it!=root->wordsHavingThisPrefix.end(); j++, it++){
                    temp.push_back(*it);
                }
                res.push_back(temp);
            }
            while(i++ < prefix.size()) res.push_back({});
            return res;
        }
        
    };
    
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for(string p : products){
            trie.insert(p);
        }
        return trie.find(searchWord);
    }
};
