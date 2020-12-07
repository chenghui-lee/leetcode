// KMP
// Time: O(n)
// Space: O(n)
class Solution {
public:
    
    vector<int> build(string p){
        int m = p.length();
        vector<int> table(m+1);
        int i=0, j = -1;
        table[0] = -1;
        while(i < m){
            while((j>=0) && p[i] != p[j]) j = table[j];
            i++, j++;
            table[i] = j;
        }
        return table;
    }
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev(s);
        
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;
        int m = temp.size();
        
        vector<int> table = build(temp);
        //for(auto& x : table) cout << x << " ";
        return rev.substr(0, n - table[m]) + s;
    }
};
