// Fenwick Tree
class Solution {
public:
    int arr[100001] = {0};
    
    int createSortedArray(vector<int>& instructions) {
        int MOD = (int) 1e9 + 7;
        int res = 0, n = instructions.size();
        for(int i=0; i<n; i++){
            res = (res + min(query(instructions[i] - 1), i - query(instructions[i]))) % MOD;
            update(instructions[i], 1);
        }
        return res;
    }
    
    void update(int x, int val){
        while(x < 100001){
            arr[x] += val;
            x += x & -x;
        }
    }
    
    int query(int x){
        int sum = 0;
        while(x>0){
            sum += arr[x];
            x -= x & -x;
        }
        return sum;
    }
};
