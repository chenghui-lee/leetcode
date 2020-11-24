
class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        stack<int> st;
        int num = 0;
        char operation = '+';
        
        for (int i = 0; i < n; i++) {
            char x = s[i];
            // somehow if (x==' ') continue, not work
            if (isdigit(x)) {
                num = num * 10 + (x - '0');
            }
            
            if (!isdigit(x) && !iswspace(x)|| i == n - 1) {
                if (operation == '-') {
                    st.push(-num);
                } else if (operation == '+') {
                    st.push(num);
                } else if (operation == '*') {
                    int temp = st.top();
                    st.pop();
                    st.push(temp * num);
                } else if (operation == '/') {
                    int temp = st.top();
                    st.pop();
                    st.push(temp / num);
                }
                operation = x;
                num = 0;
            }
        }
        int res = 0;
        while (st.size() != 0) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
