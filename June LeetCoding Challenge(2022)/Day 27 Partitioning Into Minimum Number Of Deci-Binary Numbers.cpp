class Solution {
public:
    int minPartitions(string n) {
        int mxNum = 0;
        for(char x : n){
            int d = x - '0';
            mxNum = max(mxNum, d);
        }
        return mxNum;
    }
};
