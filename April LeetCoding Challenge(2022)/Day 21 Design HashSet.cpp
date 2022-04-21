class MyHashSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<int>> match;
    vector<bool> c;
    MyHashSet() {
        vector<bool> t(149900, false);
        c = t;
    }
    
    void add(int key) {
        int k = key%170167;
        if(contains(key)) return;
        c[k] = true;
        match[k].push_back(key);
        
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int k = key%170167;
        auto it = find(match[k].begin(), match[k].end(), k);
        match[k].erase(it);
        if(match[k].size() == 0) c[k] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int k = key%170167;
        if(c[k] == false) return false;
        for(auto x : match[k]) if(x == key)return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
