class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);
        
        for(int i=0; i<n; i++){
            int t = 0;
            for(char ch : words[i]){
                t |= (1 << (ch - 'a'));
            }
            mask[i] = t;
        }
        int res = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if ((mask[i] & mask[j]) == 0) {
                    res = max(res, int(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};
