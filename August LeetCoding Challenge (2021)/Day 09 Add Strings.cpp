class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<char> n1, n2;
        
        for(auto& ch : num1) n1.push(ch);
        for(auto& ch : num2) n2.push(ch);
        
        int carry = 0, cur = 0;
        string res = "";
        while(n1.size() > 0 && n2.size() > 0){
            cur = (n1.top() - '0') + (n2.top() - '0') + carry;
            carry = cur / 10;
            cur %= 10;
            n1.pop(), n2.pop();
            res = to_string(cur) + res;
        }

        while(n1.size() > 0){
            cur = (n1.top() - '0') + carry;
            carry = cur / 10;
            cur %= 10;
            n1.pop();
            res = to_string(cur) + res;
        }
        while(n2.size() > 0){
            cur = (n2.top() - '0') + carry;
            carry = cur / 10;
            cur %= 10;
            n2.pop();
            res = to_string(cur) + res;
        }
        if (carry) res = '1' + res;
        return res;
    }
};
