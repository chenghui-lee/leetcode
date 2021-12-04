struct Trie{
    bool isWord;
    vector<Trie*> child;
    Trie(): child(vector<Trie*>(26, nullptr)), isWord(false){}
       
    void insert_reverse(string word){
        Trie* cur = this;
        for(int i=word.size()-1; i>=0; i--){
            int idx = word[i] - 'a';
            if (!cur->child[idx]) cur->child[idx] = new Trie();
            cur = cur->child[idx];
        }
        cur->isWord = 1;
    }
};

class StreamChecker {
public:
    Trie* root;
    int longestLength = 0;
    vector<char> q;
    
    StreamChecker(vector<string>& words) {
        root = new Trie();
        for(auto x : words){
            root->insert_reverse(x);
            if (x.size() > longestLength){
                longestLength = x.size();
            }
        }
    }
    
    bool query(char letter) {
        q.insert(q.begin(), letter);
        if (q.size() > longestLength) q.pop_back();
        Trie* cur = root;
        for(int i=0; i<q.size(); i++){
            int idx = q[i] - 'a';
            if (cur->isWord) return true;
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return cur->isWord;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
