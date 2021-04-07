class Solution {
public:
    bool halvesAreAlike(string s) {
        int v1=0, v2=0;
        for(int i=0; i<s.size()/2; i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') v1++;
        }    
        for(int i=s.size()/2; i<s.size(); i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') v2++;
        }
        return v1==v2;
    }
};
