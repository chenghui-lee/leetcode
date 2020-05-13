class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        stack<char> s;
        string result;
        int index = 0; // to count the number of delection
        for (int i =0; i<num.size(); i++){
            while (k>0 && !s.empty() && s.top() > num[i]){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        // to delete the balance
        while (k--){
            s.pop();
        }
        while (!s.empty()){
            result += s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());
        // remove leading zero
        while (result.size() > 1 && result[0] == '0'){
            result.erase(0,1);
        }
        return result;
    }
};
