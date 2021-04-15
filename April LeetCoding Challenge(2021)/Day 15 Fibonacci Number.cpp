class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        else if (n <= 2) return 1;
        
        int a = 1, b = 1, c = 2;
        for(int i=3; i<=n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
