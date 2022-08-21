class Solution {
public:
    /*
    The idea is starting from the reverse order,
    instead of starting with ??? to target, we 
    start from target to ???
    
    Take stamp = 'abc' and target = 'aabcc',
    we fit stamp into target,
    target = 'a???c',
    then we fit again, target = '???c',
    finally one more, target = '????'
    
    */
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> visited(target.size(),false);
        int stars = 0;
        vector<int> res;
        
        while(stars < target.size()){
            bool has_replacement = false;
            for(int i=0; i<=target.size() - stamp.size(); i++){
                if (!visited[i] && canReplace(target, i, stamp)){
                    doReplacement(target, i, stamp, stars);
                    visited[i] = true;
                    has_replacement = true;
                    res.push_back(i);
                    if (stars == target.size()) break; // exit early
                }
            }
            if (!has_replacement){ // if no replacement is done
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool canReplace(string& target, int start, string stamp){
        for(int i=0; i<stamp.size(); i++){
            if (target[i + start] != '?' && target[i + start] != stamp[i]) {
                return false;
            }
        }
        return true;
    }
    
    void doReplacement(string& target, int start, string stamp, int& stars){
        for(int i=0; i<stamp.size(); i++){
            if (target[i + start] != '?'){
                target[i + start] = '?';
                stars++;
            }
        }
    }
};
