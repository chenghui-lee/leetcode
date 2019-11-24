public int climbStairs(int n) {
        int result =0,a=0,b=1;
        if (n==0)
            return 0;
        else if (n==1)
            return 1;
        for (int i=2;i<=n;i++){
            result = a+b;
            a=b;
            b=result;
        }
        return result;
    }
// can use on fib number also
