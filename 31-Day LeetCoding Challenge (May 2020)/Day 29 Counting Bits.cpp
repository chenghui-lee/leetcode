class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        for (int i=0;i<num+1;i++){
            int count = 0;
            int t = i;
            while(t>0){
                t = t&(t-1);
                count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};
