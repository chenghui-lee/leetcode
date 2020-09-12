// By using recursion
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        dfs(k, n, 1, cur);
        return ans;
    }
    
    void dfs(int k, int n, int search, vector<int>& cur){
        if(k == 0){
            if(n == 0){
                ans.push_back(cur);
            }
            return;
        }
        
        for(int i=search; i<=9; i++){
            if(i > n) return;
            cur.push_back(i);
            dfs(k-1, n-i, i+1, cur);
            cur.pop_back();
        }
    }
};

// By using bit masking, from 0 to 2^9
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for(int i=0; i<(1<<9); i++){
            vector<int> cur;
            int sum = 0;
            for(int j=1; j<=9; j++){
                if(i & (1 << (j-1))){
                    sum += j;
                    cur.push_back(j);
                }
            }
            if(cur.size() == k && sum == n) ans.push_back(cur);
            
        }
        return ans;
    }
};
