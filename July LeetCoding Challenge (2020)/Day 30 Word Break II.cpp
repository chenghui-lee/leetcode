class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
        return wbreak(dictionary, s);
    }
private:
    unordered_map<string, vector<string>> memory;
    
    vector<string> append(const vector<string>& prefix, string word){
        vector<string> result;
        for(auto s : prefix){
            result.push_back(s + " " + word);
        }
        return result;
    }
    
    const vector<string> wbreak(unordered_set<string>& dict, string& s){
        if(memory.count(s)) return memory[s];
        vector<string> ans;
        if(dict.count(s)) ans.push_back(s);
        
        for(int i=1; i<s.size(); i++){
            string rightSide = s.substr(i);
            if(!dict.count(rightSide)) continue;
            string leftSide  = s.substr(0, i);
            
            vector<string> leftans = append(wbreak(dict, leftSide), rightSide);
            ans.insert(ans.end(), leftans.begin(), leftans.end());
        }
        memory[s].swap(ans); // memory[s] replaced by ans
        return memory[s];
    }
};
