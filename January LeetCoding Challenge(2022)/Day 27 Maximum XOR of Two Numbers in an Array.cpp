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
