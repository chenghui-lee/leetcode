class Solution {
public:
    int low = 0, maxLen = 0;
    void expand(string& s, int i, int j){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--, j++;
        }
        if (j - i - 1 > maxLen){
            maxLen = j - i - 1;
            low = i+1;
        }
    }
    string longestPalindrome(string s) {
        for(int i=0; i<s.size(); i++){
            expand(s, i, i);
            expand(s, i, i+1);
        }
        return s.substr(low, maxLen);
    }
};
