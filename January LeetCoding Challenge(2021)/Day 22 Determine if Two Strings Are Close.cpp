class Solution {
public:

    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        else if (word1 == word2) return true;
        
        vector<int> charA(26);
        vector<int> charB(26);
        set<char> a;
        set<char> b;
        
        for(auto& x : word1){
            charA[x - 'a']++;
            a.insert(x);
        }
        for(auto& x : word2){
            charB[x - 'a']++;
            b.insert(x);
        }
        
        sort(charA.begin(), charA.end());
        sort(charB.begin(), charB.end());
        return charA==charB && a==b;
        
    }
};
