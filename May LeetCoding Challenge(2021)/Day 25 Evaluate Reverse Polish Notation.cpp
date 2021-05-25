class Solution {
public:
    string eval(string num1, string num2, string operator_){
        int a = stoi(num1), b = stoi(num2);
        if (operator_ == "/") return to_string(a/b);
        else if (operator_ == "*") return to_string(a * b);
        else if (operator_ == "+")return to_string(a + b);
        else return to_string(a - b);
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        
        for(auto x : tokens){
            if (isdigit(x[0]) || (x[0] == '-' && x.size() > 1)) s.push(x);
            else{
                auto b = s.top(); s.pop();
                auto a = s.top(); s.pop();
                s.push(eval(a, b, x));
            }
        }
        auto res = s.top();
        return stoi(res);
    }
};
