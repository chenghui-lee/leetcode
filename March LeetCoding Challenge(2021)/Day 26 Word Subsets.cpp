class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> totalChar(26);
        for(auto word : B){
            vector<int> temp(26);
            for(auto ch : word){
                temp[ch - 'a']++;
            }
            for(int i=0; i<26; i++){
                totalChar[i] = max(totalChar[i], temp[i]);
            }
        }
        
        vector<string> res;
        for(auto word : A){
            vector<int> temp(26);
            for(auto ch : word){
                temp[ch - 'a']++;
            }
            bool qualified = true;
            for(int i=0; i<26; i++){
                if (temp[i] < totalChar[i]){
                    qualified = false;
                    break;
                }
            }
            if (qualified){
                res.push_back(word);
            }
        }
        return res;
    }
};
