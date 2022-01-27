class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        
        for(int i=31; i>=0; i--){
            mask |= (1<<i);
            set<int> s;
            for(int x : nums){
                int prefix = x & mask; // left part of the number
                s.insert(prefix);
            }
            int assume = res | (1 << i);
            for(int prefix : s){
                int target = assume ^ prefix;
                if(s.find(target) != s.end()){
                    res = assume;
                    break;
                }
            }
        }
        return res;
    }
};

// using Trie
class Solution {
private:
    struct Trie{
        vector<Trie*> children;
        Trie(): children(vector<Trie*>(2, nullptr)){};
    };
    
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        
        Trie* root = new Trie();
        for(int x : nums){
            Trie* cur = root;
            for(int i=31; i>=0; i--){
                int curBit = (x >> i) & 1;
                if (cur->children[curBit] == nullptr){
                    cur->children[curBit] = new Trie();
                }
                cur = cur->children[curBit];
            }
        }
        
        int res = INT_MIN;
        for(int x : nums){
            Trie* cur = root;
            int curSum = 0;
            for(int i=31; i>=0; i--){
                int curBit = (x >> i) & 1;
                if (cur->children[curBit ^ 1] != nullptr){
                    curSum += (1 << i);
                    cur = cur->children[curBit ^ 1];
                }else{
                    cur = cur->children[curBit];
                }
            }
            res = max(res, curSum);
        }
        
        return res;
    }
};
