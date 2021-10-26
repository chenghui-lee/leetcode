class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for(int i=0; i<deck.size(); i++){
            m[deck[i]]++;
        }
        int res = 0;
        for(auto p : m){
            res = __gcd(res, p.second);
        }
        return res > 1;
    }
};
