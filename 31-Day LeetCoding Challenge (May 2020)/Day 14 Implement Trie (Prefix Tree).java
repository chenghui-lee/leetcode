// https://leetcode.com/articles/implement-trie-prefix-tree/#
// http://zxi.mytechroad.com/blog/data-structure/leetcode-208-implement-trie-prefix-tree/
class Trie {

    class TrieNode{
        private boolean isWord;
        private TrieNode[] children;
        public TrieNode(){
            isWord = false;
            children = new TrieNode[26];
        }
    }
    
    private TrieNode root;
    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode current = root;
        for (int i =0; i<word.length(); i++){
            int index = (int)(word.charAt(i) - 'a');
            if (current.children[index] == null){
                current.children[index] = new TrieNode();
            }
            current = current.children[index];
        }
        current.isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode node = find(word);
        return node != null && node.isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode node = find(prefix);
        return node != null;
    }
    
    // This function can be used to find both prefix and word
    private TrieNode find(String prefix){
        TrieNode current = root;
        for (int i =0 ; i<prefix.length(); i++){
            int index = (int)(prefix.charAt(i) - 'a');
            if (current.children[index] == null){
                return null;
            }
            current = current.children[index];
        }
        return current;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
