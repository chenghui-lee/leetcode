class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        
        for(string w : words){
            string temp = "";
            for(int i=0; i<w.size(); i++){
                temp += dict[w[i] -'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }
};
