class Solution {
public:
    int mask(const string& word){
        int msk = 0;
        for(auto ch : word){
            msk |= (1 << (ch - 'a'));
        }
        return msk;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> wordCount; // mask, number of string
        for(auto& w : words){
            wordCount[mask(w)]++;
        }
        
        vector<int> res;
        for(auto& puzz : puzzles){
            // count the number of words that only contains the first letter of puzz
            int first = 1 << (puzz[0] - 'a');
            int cnt = wordCount[first];
            
            // find the remaining characters
            int msk = mask(puzz.substr(1));
            
            // iterate through the subset of the mask, since the target must only contains letters in puzz, we can go thru all the possibilities for the letters in puzz
            for(int submask = msk; submask > 0; submask = (submask -1) & msk){
                cnt += wordCount[submask | first]; // include the first char
            }
            res.push_back(cnt);
        }
        return res;
    }
};
