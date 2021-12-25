class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        
        char sign = '+';
        int num = 0;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if (isdigit(ch)){
                num = num * 10 + (ch - '0');
            }
            if (!isdigit(ch) && !iswspace(ch) || i == n-1){
                if (sign == '+'){
                    st.push(num);
                }else if (sign == '-'){
                    st.push(-num);
                }else if (sign == '*'){
                    int t = st.top();
                    st.pop();
                    st.push(t * num);
                }else if (sign == '/'){
                    int t = st.top();
                    st.pop();
                    st.push(t / num);
                }
                sign = ch;
                num = 0;
            }
        }
        int res = 0;
        while(!st.empty()){
            res += st.top(); 
            st.pop();
        }
        return res;
    }
};
