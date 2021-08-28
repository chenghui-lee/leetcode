class Solution {
public:
    // check a is subsequence of b
    bool isSubsequence (string a, string b){
        if(a.size() > b.size()) return false;
        int i = 0;
        for(auto& ch : b){
            if (i < a.size() && a[i] == ch) i++;
        }
        return i == a.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        for(int i=0; i<strs.size(); i++){
            int j = 0;
            for(; j<strs.size(); j++){
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) break;
            }
            // if this string is not subsequence of any other string
            if (j == strs.size()){
                res = max(res, (int)strs[i].size());
            }
        }
        
        return res;
    }
};
