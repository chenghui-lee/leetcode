class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> set(begin(words),end(words));
        int n = words.size();

        for(string& s: words){
            for(int i = 1 ; i < s.size(); i++){
               set.erase(s.substr(i));
            }
        }
      
        int ans = 0;
        for(string s: set) ans += s.size() + 1;
        return ans;
    }
};
