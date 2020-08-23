// https://leetcode.com/problems/stream-of-characters/discuss/807429/C%2B%2B-trie-solution-simple-and-clean-explained
class StreamChecker {
private:
    
    
    class Trie{
    public:
        bool isWord;
        Trie* children[26];
        
        Trie(){
            isWord = false;
            for(int i=0;i<26;i++){
                this->children[i] = NULL;
            }
        }
        
        void insert_reversed(string word) {
            Trie* root = this;
            for(int i=word.length()-1; i>=0; i--)
            {
                int index = word[i] - 'a';
                if (root->children[index] == NULL)
                    root->children[index] = new Trie();
                root = root->children[index];
            }
            root->isWord = true;
        }
        
    };
    
    
    
public:
    Trie trie;
    vector<char> queries;
    int longest_word = 0;
    
    StreamChecker(vector<string>& words) {
        for(auto w : words){
            trie.insert_reversed(w);
            if(w.size() > longest_word){
                longest_word = w.size();
            }
        }
    }
    
    bool query(char letter) {
        queries.insert(queries.begin(), letter);
        if(queries.size() > longest_word) queries.pop_back();
        
        Trie* cur = &trie;
        for(int i=0; i<queries.size(); i++){
            int next = queries[i] - 'a';
            if(cur->isWord) return true;
            if(!cur->children[next]) return false;
            cur = cur->children[next];
        }
        return cur->isWord;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
