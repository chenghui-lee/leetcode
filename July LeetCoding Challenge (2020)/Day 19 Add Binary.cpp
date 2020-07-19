class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;
        while(m >= 0 || n >= 0){
            int sum = carry;
            if (m >= 0){
                sum += a[m--] - '0';
            }
            if (n >= 0){
                sum += b[n--] - '0';
            }
            result.insert(0, to_string(sum%2));
            carry = sum / 2 ;
        }
        if (carry != 0) {
            result.insert(0, to_string(carry));
        }
        return result;
    }
};
