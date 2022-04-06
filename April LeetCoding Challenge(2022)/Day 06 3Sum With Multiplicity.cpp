class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> m; // num, count
        int MOD = 1e9 + 7;
        for(int x : arr) m[x]++;
        long long res = 0;
        for(auto i : m){
            for(auto j : m){
                int num1 = i.first, num2 = j.first, num3 = target - num1 - num2;
                if (m.find(num3) == m.end()) continue;
                else{
                    if (num1 == num2 && num1 == num3){
                        // nCr, where r is 3
                        // nC3, = n! / (n-k)!(k!)
                        res += i.second * (i.second - 1) * (i.second-2) / 6 % MOD;
                    }else if (num1 == num2 && num1 != num3){
                        // nC2 * m[num3]
                        res += i.second * (i.second - 1) / 2 * m[num3] % MOD;
                    }else if (num1 < num2 && num2 < num3){
                        res += i.second * j.second * m[num3] % MOD;
                    }
                }
            }
        }
        return (int) res % MOD;
    }
};
