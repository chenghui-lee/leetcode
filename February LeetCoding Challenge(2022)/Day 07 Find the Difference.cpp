class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        
        for(auto ch : s){
            cnt1[ch - 'a']++;
        }
        for(auto ch : t){
            cnt2[ch - 'a']++;
        }
        for(int i=0; i<26; i++){
            if (cnt1[i] != cnt2[i]) return char(i + 'a');
        }
        return ' ';
    }
};
