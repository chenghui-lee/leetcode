struct Trie{
    vector<Trie*> children;
    int wordCount;
    Trie(): children(vector<Trie*>(26, nullptr)), wordCount(0){}

    void insert(string s){
        Trie* cur = this;
        for(int i=0; i<s.size(); i++){
            int idx = s[i] - 'a';
            if (!cur->children[idx]) cur->children[idx] = new Trie();
            cur = cur->children[idx];
            cur->wordCount++;
        }
    }

    void query(string s, vector<int>& res, int j){
        Trie* cur = this;
        for(int i=0; i<s.size(); i++){
            int idx = s[i] - 'a';
            cur = cur->children[idx];
            res[j] += cur->wordCount;
        }
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for(string w : words){
            trie->insert(w);
        }

        int n = words.size();
        vector<int> res(n, 0);
        
        for(int i=0; i<n; i++){
            string s = words[i];
            trie->query(s, res, i);
        }
        return res;
    }
};