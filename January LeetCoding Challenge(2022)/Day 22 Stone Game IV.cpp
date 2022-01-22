class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> canWin(n+1, false);
        canWin[1] = true;
        
        for(int i=2; i<=n; i++){
            for(int j=1; j*j <= i; j++){ // number of stones to be taken by alice
                if (!canWin[i - j*j]){ // next step has no move left, alice will win
                    canWin[i] = true;
                    break;
                }
            }
        }
        return canWin[n];
    }
};
