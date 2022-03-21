class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> lastIndex(26, -1);
        for(int i=0; i<n; i++){
            lastIndex[s[i] - 'a'] = i;
        }
        
        vector<int> res;
        int start = 0, end = 0;
        for(int i=0; i<n; i++){
            end =  max(end, lastIndex[s[i] - 'a']);
            if (i == end){
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
