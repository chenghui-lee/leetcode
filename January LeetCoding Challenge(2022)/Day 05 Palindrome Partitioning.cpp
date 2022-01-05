class Solution {
public:
    vector<vector<string>> res;
    
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void dfs(string& s, int start, vector<string>& curr){
        int n = s.size();
        if (start >= n) res.push_back(curr);
        for(int i=start; i<n; i++){
            if (isPalindrome(s, start, i)){
                curr.push_back(s.substr(start, i - start + 1));
                dfs(s, i+1, curr);
                curr.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        dfs(s, 0, curr);
        return res;
    }
};
