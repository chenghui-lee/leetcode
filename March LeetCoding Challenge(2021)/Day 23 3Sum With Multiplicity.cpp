class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int MOD = 1e9 + 7, n = arr.size();
        
        unordered_map<int, long> m; // num, count
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        long res = 0;
        for(auto num1 : m){
            for(auto num2 : m){
                int a = num1.first, b = num2.first, c = target - a - b;
                if (!m.count(c)) continue;
                if(a == b && b == c){
                    res += m[a] * (m[a]-1) * (m[a] - 2) / 6 % MOD; // nCk = n! / (n-k)!*k!, where k here is 3, so / 6 ...its like count C 3
                }else if (a == b && b != c){
                    res += m[a] * (m[a] - 1)/2 * m[c] % MOD; // count C 2 * another
                }else if (a < b && b < c){
                    res += m[a] * m[b] * m[c] % MOD;
                }
            }
        }
        
        return (int) res % MOD;
    }
};

// TLE on test 38 / 71
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int MOD = 1e9 + 7, n = arr.size();
        
        unordered_map<int, vector<int>> m; // num, [indexes]
        for(int i=0; i<n; i++){
            m[arr[i]].push_back(i);
        }
        long res = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int t = target - arr[i] - arr[j];
                if (t>=0 && m.count(t)){
                    auto idx = m[t];
                    int k = 0;
                    while(k < idx.size() && idx[k] <= j){
                        k++;
                    }
                    int num = idx.size() - k;
                    res = (res + num) % MOD; 
                }
            }
        }
        return (int) res;
    }
};
