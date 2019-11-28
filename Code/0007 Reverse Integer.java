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

// Old Solution
 public int reverse(int x) {
        String temp = Integer.toString(x);
        String result = "";
        
        if (temp.charAt(0) == '-'){
            result+= "-";
            for (int i = temp.length()-1;i>=1;i--){
            result += temp.charAt(i);
            }
        } else {
            for (int i = temp.length()-1;i>=0;i--){
            result += temp.charAt(i);
            }
        }
        double lift = Double.parseDouble(result);
        if (lift >Integer.MAX_VALUE || lift <Integer.MIN_VALUE)
            return 0;
        x = Integer.parseInt(result);
        return x;
    }
