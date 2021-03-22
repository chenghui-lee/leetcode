// Credit: lee215
class Solution {
public:
    
    string tolow(string s){
        for(auto& ch : s){
            ch = tolower(ch);
        }
        return s;
    }
    
    string tovow(string s){
        for(auto& ch : s){
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                ch = '#';
            }
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> dict(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vowel; // pattern, 1st encounter string
        
        for(auto s : wordlist){
            string low = tolow(s), vow = tovow(s);
            cap.insert({low, s}); // use insert instead of map[key] = 'val' to avoid replacement
            vowel.insert({vow, s});
        }
        
        for(int i=0; i<queries.size(); i++){
            string& s = queries[i];
            if (dict.count(s)) continue;
            
            string low = tolow(s), vow = tovow(s);
            if (cap.count(low)) s = cap[low];
            else if (vowel.count(vow)) s = vowel[vow];
            else s = "";
        }
        return queries;
    }
};
