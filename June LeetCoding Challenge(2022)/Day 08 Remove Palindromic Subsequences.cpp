class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if (s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if (s.size() == 0) return 0;
        else if (isPalindrome(s)) return 1;
        return 2; // remove all the 'a', then 'b'
    }
};
