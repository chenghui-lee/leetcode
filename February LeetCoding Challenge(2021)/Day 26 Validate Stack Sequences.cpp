class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        if (n == 0) return true;
        int j = 0;
        for(int i=0; i<n; i++){
            st.push(pushed[i]);
            while(st.size() && st.top() == popped[j]){
                j++;
                st.pop();
            }
        }
        
        return  j == n && st.empty();
    }
};
