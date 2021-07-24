class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end()), visited;
        vector<vector<string>> res;
        queue<vector<string>> q;
        
        if (st.find(endWord) == st.end()) return res;
        q.push({beginWord});
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto curPath = q.front(); q.pop();
                string last = curPath.back();
                
                for(int i=0; i<last.size(); i++){
                    char ori = last[i];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        last[i] = ch;
                        if (st.find(last) != st.end()){
                            auto newPath = curPath;
                            newPath.push_back(last);
                            visited.insert(last);
                            if (last == endWord) res.push_back(newPath);
                            else q.push(newPath);
                        }
                    }
                    last[i] = ori;
                }
            }
            for(auto& s : visited) st.erase(s);
        }
        return res;
    }
};
