class Solution {
public:
    int palindrome(string s, int i, int j){
        int count = 0;
        while(i>=0 && j<s.size() && s[i] == s[j]){
            count++;
            i--, j++;
        }
        return count;
    }
    
    int countSubstrings(string s) {
        if (s.size() <= 1) return s.size();
        int res = 0;
        
        for(int i=0; i<s.size(); i++){
            res += palindrome(s, i, i); // 1 char
            res += palindrome(s, i, i+1); // 2 char
        }
        return res;
    }
};
