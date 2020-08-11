class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        vector<int> bucket(n+1, 0);
        for(int& x : c){
            if(x >= n) bucket[n]++;
            else bucket[x]++;
        }
        int count = 0;
        for(int i=n; i>=0; i--){
            count += bucket[i];
            if(count >= i) return i;
        }
        return 0;
    }
};
