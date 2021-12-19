class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        
        int k = 0;
        string cur = "";
        for(auto ch : s){
            if (isdigit(ch)){
                k = k * 10 + (ch - '0');
            }else if (ch == '['){
                numStack.push(k);
                k = 0;
                strStack.push(cur);
                cur = "";
            }else if (ch == ']'){
                string temp = cur;
                cur = strStack.top(); strStack.pop();
                for(int i=numStack.top(); i>0; i--){
                    cur += temp;
                }
                numStack.pop();
            }else{
                cur += ch;
            }
        }
        return cur;
    }
};
