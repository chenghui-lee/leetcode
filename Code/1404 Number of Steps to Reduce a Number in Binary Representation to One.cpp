class Solution {
public:
    int numSteps(string s) {
        char carry = '0';
        int res = 0;
        for(int i=s.size()-1; i>=0; i--){
            if (i == 0){
                if (carry == '1') res++;
                break;
            }
            if (s[i] == '1'){
                if (s[i] == carry){
                    res++;
                }else{
                    carry = '1';
                    res += 2;
                }
            }else{
                if (s[i] == carry){
                    res++;
                }else{
                    carry = '1';
                    res += 2;
                }
            }
        }
        return res;
    }
};
