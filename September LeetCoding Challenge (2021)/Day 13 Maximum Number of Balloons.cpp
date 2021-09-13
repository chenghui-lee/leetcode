class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for(auto& ch : text){
            m[ch]++;
        }
        return min(m['b'], min(m['a'], min(m['l']/2, min(m['o']/2, m['n']))));
    }
};
