// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91049/Java-O(n)-solution-using-bit-manipulation-and-HashMap

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
                if(s.count(target)){
                    res = assume;
                    break;
                }
            }
        }
        return res;
    }
};
