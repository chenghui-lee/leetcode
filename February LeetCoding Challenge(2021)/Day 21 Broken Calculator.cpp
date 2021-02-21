class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        while(Y > X){
            if (Y%2 == 0) Y /= 2;
            else Y++;
            res++;
        }
        return res + X - Y;
    }
};
