class Solution {
private:
    struct Trie{
        vector<Trie*> child;
        string word;
        Trie(): child(vector<Trie*>(26, nullptr)), word(""){};
    };
    
    Trie* buildTrie(vector<string> words){
        Trie* root = new Trie();
        for(auto word : words){
            Trie* cur = root;
            for(auto ch : word){
                if (!cur->child[ch -'a']){
                    cur->child[ch-'a'] = new Trie();
                }
                cur = cur->child[ch-'a'];
            }
            cur->word = word;
        }
        return root;
    }
public:
    
    void dfs(vector<vector<char>>& board, vector<string>& res, int i, int j, Trie* root){
        char t = board[i][j];
        if (t == '.' || !root->child[t - 'a']) return;
        
        root = root->child[t - 'a'];
        if (root->word != ""){
            res.push_back(root->word);
            root->word = "";
        }
        board[i][j] = '.';
        if (i < board.size()-1) dfs(board, res, i + 1, j, root);
        if (j < board[0].size()-1) dfs(board, res, i, j + 1, root);
        if (i > 0) dfs(board, res, i - 1, j, root);
        if (j > 0 ) dfs(board, res, i, j - 1, root);
        
        board[i][j] = t;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        Trie* root = buildTrie(words);
        vector<string> res;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(board, res, i, j, root);
            }
        }
        return res;
    }
};
