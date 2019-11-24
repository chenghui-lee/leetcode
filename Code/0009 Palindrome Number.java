public static boolean isPalindrome(int x){
        String temp = Integer.toString(x);
        StringBuilder sb = new StringBuilder();
        sb.append(temp);
        sb.reverse();
        String result = sb.toString();
        return result.equals(temp);
    }
	
	// Without using String
public static boolean isPalindrome(int x){
        if (x<0) return false;
        int reverse =0;
        int hold = x;
        
        while(x !=0){
            reverse = reverse*10 + x%10; // Reverse x10 then plus last digit
            x /= 10; // Remove last digit
        }
        return reverse == hold;
    }
