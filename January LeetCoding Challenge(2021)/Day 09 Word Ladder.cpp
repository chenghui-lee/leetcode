// One directional BFS, TLE for some reasons
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 1;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                string cur = q.front();
                q.pop();
                if (cur == endWord) return res;
                dict.erase(cur);
                
                for(int j=0; j<cur.size(); j++){ // replace every character in the string to check neighbor
                    char temp = cur[j];
                    for(int chg=0; chg<26; chg++){
                        cur[j] = 'a' + chg;
                        if (dict.count(cur)) q.push(cur);                                       
                    }
                    cur[j] = temp;
                }
            }
            res++;
        }
        return 0;
    }
};

// Bi-directional BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> beginSet, endSet, dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int res =  1;
        
        while(beginSet.size() && endSet.size()){
            if (beginSet.size() > endSet.size()){ // swab, so that we always process the smaller one
                unordered_set<string> s = endSet;
                endSet = beginSet;
                beginSet = s;
            }
            
            unordered_set<string> newSet;
            for(auto w : beginSet){
                for(int i=0; i<w.size(); i++){
                    char c = w[i];
                    for(int j=0; j<26; j++){
                        w[i] = 'a' + j;
                        if (endSet.count(w)) return res +1;
                        if (dict.count(w)){
                            dict.erase(w);
                            newSet.insert(w);
                        }
                    }
                    w[i] = c;
                }
            }
            res++;
            beginSet = newSet;
        }
        return 0;
    }
};
