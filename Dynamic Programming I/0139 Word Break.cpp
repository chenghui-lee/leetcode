class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int n = s.size();
        
        for(auto w : wordDict){
            st.insert(w);
        }
        vector<bool> dp(n + 1, false); // until i-th (not index) character, is inside wordDict or not
        dp[0] = true; // empty string, true
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if (dp[j] && st.find(s.substr(j, i-j)) != st.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
