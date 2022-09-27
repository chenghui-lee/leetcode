class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n);
        vector<int> right(n);
        
        // right
        int force = 0;
        for(int i=0; i<n; i++){
            if (dominoes[i] == 'R') force = n;
            else if (dominoes[i] == 'L') force = 0;
            else force = max(force-1, 0); // futher from the force origin, so -1
            right[i] = force;
        }
        force = 0;
        for(int i=n-1; i>=0; i--){
            if (dominoes[i] == 'L') force = n;
            else if (dominoes[i] == 'R') force = 0;
            else force = max(force-1, 0);
            left[i] = force;
        }
        for(int i=0; i<n; i++){
            if (left[i] > right[i]) dominoes[i] = 'L';
            else if (right[i] > left[i]) dominoes[i] = 'R';
            else dominoes[i] = '.';
        }
        return dominoes;
    }
};
