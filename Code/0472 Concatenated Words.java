// same idea with c++, but idk for what reason java pass but not c++
public class Solution {
    public static List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> result = new ArrayList<>();
        Set<String> preWords = new HashSet<>();
        Arrays.sort(words, new Comparator<String>() {
            public int compare (String s1, String s2) {
                return s1.length() - s2.length();
            }
        });
        
        for (int i = 0; i < words.length; i++) {
            if (canForm(words[i], preWords)) {
                result.add(words[i]);
            }
            preWords.add(words[i]);
        }
        
        return result;
    }
	
    private static boolean canForm(String word, Set<String> dict) {
        if (dict.isEmpty()) return false;
	boolean[] dp = new boolean[word.length() + 1];
	dp[0] = true;
	for (int i = 1; i <= word.length(); i++) {
	    for (int j = 0; j < i; j++) {
		if (!dp[j]) continue;
		if (dict.contains(word.substring(j, i))) {
		    dp[i] = true;
		    break;
		}
	    }
	}
	return dp[word.length()];
    }
}

// c++ solution
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string a, const string b){
            return a.size() < b.size();
        });
        
        vector<string> res;
        int n = words.size();
        if (n < 2) return res;
        unordered_set<string> s;
        
        for(int i=0; i<words.size(); i++){
            if (canForm(words[i], s)){
                res.push_back(words[i]);
            }
            s.insert(words[i]);
        }
        
        return res;
    }
    bool canForm(string word, unordered_set<string> dict){
        if (dict.empty()) return false;
        vector<bool> dp(word.size()+1, false);
        dp[0] = true;
        for(int i=1; i<=word.size(); i++){
            for(int j=i-1; j>=0; j--){
                if (!dp[j]) continue;
                if (dict.find(word.substr(j, i-j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[word.size()];
    }
};
