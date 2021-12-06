class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0;
        for(auto x : position){
            if (x % 2) odd ++;
            else even++;
        }
        return min(odd, even);
    }
};
