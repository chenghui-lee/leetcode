class FirstUnique {
    unordered_map<int, int> m;  
    queue<int> q;
public:
    FirstUnique(vector<int>& nums) {
        for (int i =0; i<nums.size(); i++){
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() &&m[q.front()] > 1){
            q.pop();
        }
        if (q.size() == 0){
            return -1;
        }
        
        return q.front();
        
    }
    
    void add(int value) {
        m[value]++;
        if (m[value] == 1){
            q.push(value);
        }
    }
    
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
