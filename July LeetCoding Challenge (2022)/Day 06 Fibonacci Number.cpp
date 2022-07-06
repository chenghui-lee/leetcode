class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1;
        int c = a + b;
        for(int i=2; i<=n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
