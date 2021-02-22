class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string a, string b){return a.size()==b.size()?a<b:a.size()>b.size();});
        for(auto w : d){
            int j = 0;
            for(int i=0; i<s.size(); i++){
                if (s[i] == w[j]) j++;
            }
            if (j == w.size()) return w;
        }
        return "";
        
        
    }
};
