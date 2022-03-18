class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<bool> seen(26, false);
        vector<int> lastIndex(26, -1); // last occurance index of the char in s
        string res = "";
        
        for(int i=0; i<n; i++){
            lastIndex[s[i] - 'a'] = i;
        }
        for(int i=0; i<n; i++){
            char ch = s[i];
            if (seen[ch - 'a']) continue;
            seen[ch - 'a'] = 1;
            while(!res.empty() && res.back() > ch && lastIndex[res.back() - 'a'] > i){
                seen[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(ch);
        }
        return res;
        
    }
};
