class FenwickTree {    
public:
    FenwickTree(int n): sums_(n + 1, 0) {}
    
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += LSOne(i);
        }
    }
    
    int query(int i) const {        
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= LSOne(i);
        }
        return sum;
    }
private:
    static inline int LSOne(int x) { return x & (-x); }
    vector<int> sums_;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int temp = 0;
        unordered_map<int, int> rank; // num, rank 1..k, 1 = smallest element
        for(auto x : s){
            rank[x] = ++temp;
        }
        
        FenwickTree tree(s.size());
        vector<int> res(nums.size());
        for(int i=nums.size()-1; i>=0; i--){
            res[i] = tree.query(rank[nums[i]]-1);
            tree.update(rank[nums[i]], 1);
        }
        return res;
    }
};
