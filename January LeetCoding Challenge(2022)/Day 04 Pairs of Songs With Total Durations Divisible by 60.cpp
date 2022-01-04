class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if (time.size() < 2) return 0;
        vector<int> cnt(60, 0);
        
        int res = 0;
        for(int x : time){
            if (x % 60 == 0){
                res += cnt[0];
            }else{
                res += cnt[60 - x % 60];
            }
            cnt[x%60]++;
        }
        return res;
    }
};
