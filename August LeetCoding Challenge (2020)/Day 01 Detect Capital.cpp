class Solution {
public:
    bool detectCapitalUse(string word) {
        int small = 0, big = 0;
        bool flag = word[0]>='A' && word[0]<='Z' ? true:false;
        for (char& x : word){
            if (x >='A' && x <='Z') big++;
            else small++;
        }
        if(big == word.size() || small == word.size() || big==1&&small==word.size()-1&&flag) return true;
        else return false;
    }
};
