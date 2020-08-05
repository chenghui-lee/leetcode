public class WordDictionary {

    public class TrieNode {
        public TrieNode[] children = new TrieNode[26];
        public boolean isWord;
    }
    
    private TrieNode root = new TrieNode();

    public void addWord(String word) {
        TrieNode node = root;
        for (char x : word.toCharArray()) {
            if (node.children[x - 'a'] == null) {
                node.children[x - 'a'] = new TrieNode();
            }
            node = node.children[x - 'a'];
        }
        node.isWord = true;
    }

    public boolean search(String word) {
        return searchTrie(word.toCharArray(), 0, root);
    }
    
    private boolean searchTrie(char[] array, int index, TrieNode node) {
        if (index == array.length) {
            return node.isWord;
        }
        if (array[index] == '.') {
            for (int i = 0; i < node.children.length; i++) {
                if (node.children[i] != null && searchTrie(array, index + 1, node.children[i])) {
                    return true;
                }
            }
        } else {
            return node.children[array[index] - 'a'] != null && searchTrie(array, index + 1, node.children[array[index] - 'a']);
        }
        return false;
    }
}
