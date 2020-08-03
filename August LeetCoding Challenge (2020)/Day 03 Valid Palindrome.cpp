class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(left<=right){
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;
            if(s[left] != s[right]) return false;
            left++, right--;
        }
        return true;
    }
};
