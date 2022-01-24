class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0, small = 0;
        
        bool firstCap = word[0] >= 'A' && word[0] <= 'Z';
        
        for(int i=0; i<word.size(); i++){
            if (word[i] >= 'a' && word[i] <= 'z'){
                small++;   
            }else{
                cap++;
            }
        }
        return (cap == word.size() || small == word.size() || (firstCap && cap == 1 && small == word.size() - 1));
    }
};
