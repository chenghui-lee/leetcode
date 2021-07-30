class MapSum {
public:
    struct Trie{
        vector<Trie*> child;
        int sum_;
        Trie(): child(vector<Trie*>(26, nullptr)), sum_(0) {}
    };
    /** Initialize your data structure here. */
    
    Trie* root;
    unordered_map<string, int> m;
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        Trie* cur = root;
        int old = 0;
        if (m.find(key) != m.end()){
            old = m[key];
        }
        m[key] = val;
        for(int i=0; i<key.size(); i++){
            int index = key[i] - 'a';
            if (!cur->child[index]){
                cur->child[index] = new Trie();
            }
            cur = cur->child[index];
            cur->sum_ += (val - old);
        }
    }
    
    int sum(string prefix) {
        Trie* cur = root;
        for(int i=0; i<prefix.size() && cur; i++){
            cur = cur->child[prefix[i] - 'a'];
        }
        return cur ? cur->sum_ : 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
