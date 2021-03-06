class Solution {
public:
    static bool cmp(string a, string b){
        return a.size() < b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        
        string res = "";
        for(int i=n-1; i>=0; i--){
            if (res.find(words[i] + "#") == std::string::npos){
                // cout << words[i] << " ";
                res += words[i] + "#";
            }
        }
        return res.size();
    }
};
