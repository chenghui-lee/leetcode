class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> arr(26,0);
        for(auto ch : s){
            arr[ch-'a']++;
        }
        for(auto ch : t){
            arr[ch-'a']--;
            if(arr[ch-'a'] < 0) return ch;
        }
        return NULL;
    }
};

// another solution, faster
char findTheDifference(string s, string t) {
        char c = 0;
        for (int i = 0; i < s.size(); i++) {
            c ^= s[i];
            c ^= t[i];
        }
        c ^= t.back();
        return c;
}
