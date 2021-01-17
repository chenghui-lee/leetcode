class Solution {
public:
    int res = 0;
    
    void helper(int cur, int count){
        if (count == 0){
            res++;
            return;
        }
        for(int i=cur; i<5; i++){
            helper(i, count-1);
        }
        
    }
    int countVowelStrings(int n) {
        for(int i=0; i<5; i++){
            helper(i, n-1);
        }
        return res;
    }
};
