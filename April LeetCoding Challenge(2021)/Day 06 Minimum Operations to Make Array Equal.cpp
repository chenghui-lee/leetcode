class Solution {
public:
    int minOperations(int n) {
        int sum = 0, target;
        vector<int> num(n);
        for(int i=0; i<n; i++){
            num[i] = 2*i + 1;
            sum += num[i];
        }
        target = sum / n;
        int res = 0;
        for(int i=0; i<n; i++){
            res += abs(target - num[i]);
        }
        return res / 2;
    }
};
