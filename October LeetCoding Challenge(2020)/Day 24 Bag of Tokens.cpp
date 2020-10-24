// If we play a token face up, we might as well play the one with the smallest value. 
// Similarly, if we play a token face down, we might as well play the one with the largest value.
// play tokens face up until we can't, then play a token face down 

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int low = 0, high = tokens.size() -1, res = 0, score = 0;
        
        while(low<=high){
            if (P >= tokens[low]){
                P -= tokens[low];
                score++;
                low++;
                res = max(res, score);
            }else if (score > 0){
                P += tokens[high];
                high--;
                score--;
            }else break;
        }
        return res;
    }
};
