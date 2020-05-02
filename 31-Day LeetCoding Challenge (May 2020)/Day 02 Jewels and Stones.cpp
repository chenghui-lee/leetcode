class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        set<char> s;
        for (char x : J){
            s.insert(x);
        }
        for (char x : S){
            if (s.find(x) != s.end()){
                res++;
            }
        }
        
        return res;
    }
};
