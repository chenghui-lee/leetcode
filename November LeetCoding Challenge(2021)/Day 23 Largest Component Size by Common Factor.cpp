class Solution {
public:
    unordered_map<int, int> parent; // num, parent
    void unite(int a, int b){
        int parA = find(a);
        int parB = find(b);
        if (parA > parB) parent[parA] = parB;
        else parent[parB] = parA;
    }
    int find(int x){
        if (parent.find(x) == parent.end()){
            parent[x] = x;
        }
        while(x != parent[x]) x = parent[x];
        return x;
    }
    
    int largestComponentSize(vector<int>& nums) {
        for(int x : nums){
            for(int i=2; i*i<=x; i++){
                if (x % i == 0){
                    unite(x, i);
                    unite(x, x/i);
                }
            }
        }
        int res = 1;
        unordered_map<int, int> m; // parent, frequency
        for(int x : nums){
            int par = find(x);
            res = max(res, ++m[par]);
        }
        return res;
    }
};
