class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a = 0, b = 0, c = 0, d = 0;
        auto mid = num1.find("+");
        a = stoi(num1.substr(0, mid));
        string temp = num1.substr(mid+1);
        temp.pop_back();
        b = stoi(temp);
        
        mid = num2.find("+");
        c = stoi(num2.substr(0, mid));
        temp = num2.substr(mid+1);
        temp.pop_back();
        d = stoi(temp);
        
        int front = a*c + b*d*-1;
        int back = a*d + b*c;
        return to_string(front) + "+" + to_string(back) + "i";
    }
};
