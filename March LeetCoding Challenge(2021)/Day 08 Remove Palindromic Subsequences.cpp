class Solution {
public:
    bool isPalindrome(string s){
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    }
    int removePalindromeSub(string s) {
        if (s == "") return 0;
        else if (isPalindrome(s)) return 1;
        else return 2;
    }
};
