class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if (s.find(endWord) == s.end()) return 0;
        
        int res = 0;
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            int sz = q.size();
            res++;
            for(int i=0; i<sz; i++){
                string cur = q.front(); q.pop();
                if (cur == endWord) return res;
                for(auto& ch : cur){
                    char t = ch;
                    for(int i=0; i<26; i++){
                        ch = ('a' + i);
                        if (s.find(cur) != s.end()){
                            q.push(cur);
                            s.erase(cur);
                        }
                    }
                    ch = t;
                }
            }
        }
        return 0;
    }
};

// bidirectional bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_set<string> beginSet, endSet;
        if (s.find(endWord) == s.end()) return 0;
        
        int res = 1;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        
        while(!beginSet.empty() && !endSet.empty()){
            if (beginSet.size() > endSet.size()){
                swap(beginSet, endSet);
            }
            unordered_set<string> newSet;
            for(string w : beginSet){
                for(char& ch : w){
                    char t = ch;
                    for(int i=0; i<26; i++){
                        ch = ('a' + i);
                        if (endSet.find(w) != endSet.end()){
                            return res + 1;
                        }
                        else if (s.find(w) != s.end()){
                            newSet.insert(w);
                            s.erase(w);
                        }
                    }
                    ch = t;
                }
            }
            res ++;
            beginSet = newSet;
        }
        return 0;
    }
};
