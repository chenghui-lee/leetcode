class Solution {
public:
    int count(string s, int i, int j){
        int res = 0;
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            res++;
            i--; j++;
        }
        return res;
    }
    int countSubstrings(string s) {
        if (s.size() <= 1) return s.size();
        int n = s.size();
        
        int res = 0;
        // expand around every character, count the number of palindrome
        // with the char with the middle character
        for(int i=0; i<n; i++){
            res += count(s, i, i);
            res += count(s, i, i+1);
        }
        return res;
    }
};
