class Solution {
public:
    string breakPalindrome(string palindrome) {
        int nonA = 0;
        int idx = -1, n = palindrome.size();
        // idx is the index of first non 'a' char
        if (n == 1) return "";
        
        for(int i=0; i<n; i++){
            if (palindrome[i] != 'a') {
                nonA++;
                if (idx == -1) idx = i;
            }
        }

        if (nonA > 1) palindrome[idx] = 'a'; // this is to prevent something like 'aabaa' changed to 'aaaaa'
        else palindrome[n - 1] = 'b';
        return palindrome;
    }
};
