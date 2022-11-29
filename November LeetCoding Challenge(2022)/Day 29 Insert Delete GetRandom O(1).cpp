class RandomizedSet {
public:
    unordered_map<int, int> m; // val, index
    vector<int> nums;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end()){
            return false;
        }
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()){
            return false;
        }
        int lastElement = nums.back();
        m[lastElement] = m[val];
        swap(nums[m[val]], nums.back());
        m.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
