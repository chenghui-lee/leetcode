class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for(int i=31; i>=0; i--){
            if (((1 << i) & left) != ((1 << i) & right)){
                break;
            }
            res += ((1 << i) & left);
        }
        return res;
    }
};
