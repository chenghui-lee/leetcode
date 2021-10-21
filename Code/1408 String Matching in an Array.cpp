class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string a, const string b) {return a.size() < b.size();});
        int n = words.size();
        vector<string> res;
        for(int i=0; i<n-1; i++){
            for(int j=n-1; j>i && words[j].size() > words[i].size(); j--){
                if (words[j].find(words[i]) != string::npos){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
