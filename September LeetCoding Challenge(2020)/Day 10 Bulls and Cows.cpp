class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        unordered_map<int, int> sec;
        vector<int> left;
        for(int i=0; i<secret.size(); i++){
            sec[secret[i] - '0']++;
        }
        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                sec[secret[i] - '0']--;                
                a++;
            }else{
                left.push_back(guess[i] - '0');
            }
        }
        for(int i=0; i<left.size(); i++){
            int need = left[i];
            if(sec[need] >= 1){
                sec[need]--;
                b++;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
         
        
    }
};
