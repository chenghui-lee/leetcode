class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(begin(dictionary), end(dictionary), [](const string a, const string b){ return a.size() < b.size();});
        
        vector<string> sArr;
        string cur = "";
        for(int i=0; i<sentence.size(); i++){
            if (sentence[i] == ' '){
                sArr.push_back(cur);
                cur = "";
            }else{
                cur += sentence[i];
            }
        }
        sArr.push_back(cur);
        for(int i=0; i<sArr.size(); i++){
            for(auto d : dictionary){
                if (d.size() >= sArr[i].size()) break;
                int j = 0;
                while(j < d.size() && d[j] == sArr[i][j]) j++;
                if (j == d.size()){
                    sArr[i] = d;
                    break;
                }
            }
        }
        string res = "";
        for(int i=0; i<sArr.size()-1; i++){
            res += sArr[i] + " ";
        }
        res += sArr.back();
        return res;
    }
};
