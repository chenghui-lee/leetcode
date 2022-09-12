/*
Sort tokens.
Buy at the cheapest and sell at the most expensive.


*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int low = 0, high = tokens.size() - 1;
        
        int score = 0, res = 0;
        while(low <= high){
            if (tokens[low] <= power){
                power -= tokens[low];
                score++;
                low++;
                res = max(res, score);
            }else if (score > 0){
                score--;
                power += tokens[high--];
            }else break;
        }
        return res;
    }
};
