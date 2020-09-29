class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> words;
        int maxLength = 0;
        
        for(auto w : wordDict){
            words.insert(w);
            maxLength = max(maxLength, (int)w.size());
        }
        
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i=1; i<=s.size(); i++){
            for(int j=i-1; j>=max(i-maxLength, 0); j--){
                if (dp[j] && words.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
