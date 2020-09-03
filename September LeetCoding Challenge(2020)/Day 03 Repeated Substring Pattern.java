// First solution, if s contains multiple copies of substring, the first occurance of s should be within s length
// Else it would be begining of second s

class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int index = (s + s).indexOf(s, 1);
        return  index < s.length();
    }
}

// Second solution, start from middle of the string, if the current index divides length(s)
// , we try to contruct the substring 0 to i-1, length(s)/i times. Check whether they're the same
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        for(int i=n/2; i>=1; i--){
            if(n % i == 0){
                int repeats = n / i;
                StringBuilder sb = new StringBuilder();
                String sub = s.substring(0, i);
                for(int j=0; j<repeats; j++){
                    sb.append(sub);
                }
                if(sb.toString().equals(s)) return true;
            }
        }
        return false;
    }
}
