/*
Idea:
Move all the chips at even position to 0, odd position to 1.
Theen just move either one, depends on which lower

*/
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0;
        for(auto x : position){
            if (x%2) odd++;
            else even++;
        }
        return min(even, odd);
    }
};
