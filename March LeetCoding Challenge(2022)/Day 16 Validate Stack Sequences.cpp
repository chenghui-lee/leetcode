class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0, n = pushed.size();
        for(int i=0; i<n; i++){
            s.push(pushed[i]);
            while(!s.empty() && j < n && s.top() == popped[j]){
                j++;
                s.pop();
            }
        }
        return j == n && s.empty();
    }
};
