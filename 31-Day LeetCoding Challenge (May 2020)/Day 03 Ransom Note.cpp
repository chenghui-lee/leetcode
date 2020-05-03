class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (char x : magazine){
            m[x]++;
        }
        for (char b : ransomNote){
            if (m.find(b) != m.end() && m[b] >= 1){
                m[b]--;
            }else{
                return false;
            }
        }
        return true;
    }
};
