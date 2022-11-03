class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int unpaired_same_char = 0;
        int res = 0;
        for(string w : words){
            if (w[0] == w[1]){
                if (count[w] > 0){
                    res += 4;
                    unpaired_same_char--;
                    count[w]--;
                }else{
                    count[w]++;
                    unpaired_same_char++;
                }
            }else{
                string rev = w;
                reverse(rev.begin(), rev.end());
                if (count[rev] > 0){
                    res += 4;
                    count[rev]--;
                }else{
                    count[w]++;
                }
            }
        }
        if (unpaired_same_char > 0) res += 2; // can put the same char at middle
        return res;
    }
};
