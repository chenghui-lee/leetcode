class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        if(N==1) res.push_back(0); // if single digit, zero is included
        for(int i=1; i<=9; i++){
            dfs(N-1, K, i, res);
        }
        return res;
    }
    void dfs(int len, int dist, int cur, vector<int>& res){
        if(len == 0){
            res.push_back(cur);
            return;
        }
        int lastDigit = cur % 10;
        if(lastDigit + dist <= 9) dfs(len-1, dist, cur*10+lastDigit+dist, res);
        if(lastDigit - dist >= 0 && dist != 0) dfs(len-1, dist, cur*10+lastDigit-dist, res);
    }
};
