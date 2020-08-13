class CombinationIterator {
public:
    set<string> s;
    CombinationIterator(string characters, int combinationLength) {
        for(int i=0; i<(1<<characters.size()); i++){
            if(__builtin_popcount(i) != combinationLength) continue;
            string temp;
            for(int j=0; j<characters.length(); j++){
                if(i & (1<<j)) temp += characters[j];
            }
            s.insert(temp);
        }
    }
    
    string next() {
        string res = *s.begin();
        s.erase(res);
        return res;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
