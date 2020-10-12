class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        vector<int> duplicate(26, 0);
        bool ok = false;
        vector<int> diff;
        
        for(int i=0; i<A.size(); i++){
            if (A[i] != B[i]){
                diff.push_back(i);
            }
            if (duplicate[A[i] - 'a']++) ok = true;
        }
        
        if (ok && A==B || diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]]) return true;
        return false;
    }
};
