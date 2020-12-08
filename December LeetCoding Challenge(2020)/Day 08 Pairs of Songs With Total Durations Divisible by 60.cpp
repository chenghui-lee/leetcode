// Time: O(N)
// Space: O(1)

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if (time.size() < 2)  return 0;
        vector<int> table(60, 0);
        
        int res = 0;
        
        for(auto &x : time){
            if (x%60 == 0){
                res += table[0];
            }else{
                res += table[60 - x % 60];
            }
            table[x%60]++;
        }
        
        return res;
    }
};
