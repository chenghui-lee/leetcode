class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> count(26);
        for(char ch : sentence) count[ch - 'a']++;
        for(int i=0; i<26; i++){
            if (count[i] < 1) return false;
        }
        return true;
    }
};
