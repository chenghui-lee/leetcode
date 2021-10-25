class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() -1;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(i < j){
            while(i < j && st.find(s[i]) == st.end()){
                i++;
            }
            while(i < j && st.find(s[j]) == st.end()){
                j--;
            }
            if (st.find(s[i]) != st.end() && st.find(s[j]) != st.end()){
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
