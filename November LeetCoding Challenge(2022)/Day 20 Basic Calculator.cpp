class Solution {
public:
    int calculate(string s) {
        vector<int> st;
        int n = s.size();
        int sum = 0, sign = 1;
        
        for(int i=0; i<n; i++){
            if (s[i] >= '0' && s[i] <= '9'){
                int temp = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9'){
                    temp = temp*10 + (s[i++] - '0');
                }
                sum += temp*sign;
                i--;
            }else if (s[i] == '+'){
                sign = 1;
            }else if (s[i] == '-'){
                sign = -1;
            }else if (s[i] == '('){
                st.push_back(sum);
                st.push_back(sign);
                sum = 0;
                sign = 1;
            }else if (s[i] == ')'){
                sum = sum * st.back();
                st.pop_back();
                sum += st.back(); st.pop_back();
            }
        }
        
        return sum;
        
    }
};
