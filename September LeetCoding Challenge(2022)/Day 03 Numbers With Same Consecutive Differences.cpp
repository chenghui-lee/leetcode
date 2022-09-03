class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int i=2; i<=n; i++){
            vector<int> temp;
            for(int x : cur){
                int y = x % 10;
                if (y + k <= 9){
                    temp.push_back(x * 10 + y + k);
                }
                if (y - k >= 0 && k > 0){ // the k > 0 is to avoid double counting, since we y+k already
                    temp.push_back(x * 10 + y - k);
                     
                }
            }
            cur = temp;
        }
        return cur;
    }
};
