/*
For a group of continuous same characters,
we need to delete all the group but leave only one character.

For each group of continuous same characters,
we need cost = sum_cost(group) - max_cost(group)

*/
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int i =0, j = 0, res = 0;
        while(i < n){
            int curSum = 0;
            int curMax = 0;
            while(j < n && colors[i] == colors[j]){
                curSum += neededTime[j];
                curMax = max(curMax, neededTime[j++]);
            }
            if (i != j){
                res += (curSum - curMax);
                i = j;
            }else{
                i++;
            }
        }
        return res;
    }
};
