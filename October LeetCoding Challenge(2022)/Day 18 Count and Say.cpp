// https://leetcode.com/problems/count-and-say/solutions/16043/c-solution-easy-understand/
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); i++) {
                int count = 1;
                while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                    count++;    
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};
