class Solution {
public:
    int res = 0;
    void helper(int n, int pos, vector<bool>& visited){
        if (pos > n) {
            res++;
            return;
        }
        for(int i=1; i<=n; i++){
            if (!visited[i] && (i%pos==0 || pos%i==0)){
                visited[i] = 1;
                helper(n, pos+1, visited);
                visited[i] = 0;
            }
        }
        
    }
    
    int countArrangement(int n) {
        vector<bool> visited(n+1);
        helper(n, 1, visited);
        return res;
    }
};
