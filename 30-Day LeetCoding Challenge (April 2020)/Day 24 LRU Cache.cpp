class LRUCache {
    int maxsize = 0;
    list<pair<int,int>> l; // key, value
    unordered_map<int, list<pair<int,int>>::iterator> m; // key, iterator to the list
public:
    
    LRUCache(int capacity) {
        maxsize = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()){ // if not found
            return -1;
        }
        l.splice(l.begin(),l,it->second);
        return it->second->second;
            
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()){ // if found
            l.erase(it->second);
        }
        l.push_front(make_pair(key,value));
        m[key] = l.begin();
        if (m.size() > maxsize){
            int k = l.rbegin()->first; // get the key of the last pair in the list
            l.pop_back();
            m.erase(k); // remove the element inside the map
        }
            
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 // Reference : https://github.com/grandyang/leetcode/issues/146
