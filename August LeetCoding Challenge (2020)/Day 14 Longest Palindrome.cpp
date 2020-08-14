class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int odd = 0;
        for(char& x : s){
            m[x]++;
        }
        int maxLength = 0;
        for(auto x : m){
            if(x.second%2) odd++;
            maxLength += x.second;
        }
        if(odd <= 1) return maxLength;
        return maxLength-odd+1;
        
    }
};
