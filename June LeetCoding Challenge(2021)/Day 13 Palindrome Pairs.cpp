// http://www.allenlipeng47.com/blog/index.php/2016/03/15/palindrome-pairs/
// https://leetcode.com/problems/palindrome-pairs/discuss/79195/O(n-*-k2)-java-solution-with-Trie-structure
class Solution {
public:
    vector<vector<int>> res;
    
    struct Trie{
        int pos; // storing the index in the array, if not word then -1
        vector<Trie*> child;
        vector<int> palins;
        Trie(): pos(-1), child(vector<Trie*>(26, nullptr)) {}
    };
    
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    void add(Trie* root, string word, int pos){
        for(int i=word.size()-1; i>=0; i--){
            auto ch = word[i];
            if (isPalindrome(word, 0, i)) root->palins.push_back(pos); // if word[0,i] is palindrome
            
            if (!root->child[ch - 'a']){
                root->child[ch - 'a'] = new Trie();
            }
            root = root->child[ch - 'a'];
        }
        root->pos = pos; // reach the end, aka the starting of the words (since we start from backwords) || when string is blank
        root->palins.push_back(pos);
    }
    
    void search(Trie* root, vector<string>& words, int i){
        int len = words[i].size();
        for(int j =0; j<len && root; j++){
            if (root->pos >= 0 && i != root->pos && isPalindrome(words[i], j, len-1)){
                res.push_back({i, root->pos});
            }
            char ch = words[i][j];
            root = root->child[ch - 'a'];
        }
        if (root && root->palins.size() > 0){ // check for the remaining string after the cur string ends
            for (int j : root->palins){
                if (j != i) res.push_back({i, j});
            }
        }
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie* root = new Trie();
        for(int i=0; i<words.size();i++){
            add(root, words[i], i);
        }
        for(int i=0; i<words.size(); i++){
            search(root, words, i);
        }
        return res;
    }
};
