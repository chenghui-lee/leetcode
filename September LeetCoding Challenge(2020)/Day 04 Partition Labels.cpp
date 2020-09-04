class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> lastIndex(26);
        
        for(int i=0; i<S.size(); i++){
            lastIndex[S[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        
        for(int i=0; i<S.size(); i++){
            end = max(end, lastIndex[S[i] - 'a']);
            if(i == end){
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
