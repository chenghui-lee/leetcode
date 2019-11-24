// Other's solution, more effective
public int reverse(int x) {
        boolean isNegative = false;
        
        if(x < 0) {
            x = -x;
            isNegative = true;
        }
        
        int result = 0;
        int check = 0;
        
        
        while(x > 0) {
            int mod = x % 10;
            result = result * 10 + mod;
     
            check = result;
            
            x = x / 10;
        }
        
        if(isNegative) {
            result = -result;
        }
        
        return result;
    }
