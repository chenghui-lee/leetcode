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
