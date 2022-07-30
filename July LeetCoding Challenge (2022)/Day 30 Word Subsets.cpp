class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // instead of going over all the word in words2 to check, we can simply
        // get the total max char for the entire words2 array
        
        vector<int> totalChar(26, 0);
        for(string word : words2){
            vector<int> temp(26, 0);
            for(char ch : word){
                temp[ch - 'a']++;
                totalChar[ch - 'a'] = max(totalChar[ch - 'a'], temp[ch - 'a']);
            }
        }
        
        vector<string> res;
        // then for each word in words1, just compare with the totalChar array
        for(string word : words1){
            vector<int> temp(26, 0);
            for(char ch : word){
                temp[ch - 'a']++;
            }
            bool qualified = true;
            for(int i=0; i<26; i++){
                if (temp[i] < totalChar[i]){
                    qualified = false;
                    break;
                }
            }
            if (qualified) res.push_back(word);
        }
        return res;
    }
};
