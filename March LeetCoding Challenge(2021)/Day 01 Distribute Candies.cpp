class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> m;
        for(int x : candyType){
            m[x]++;
        }
        return min(candyType.size()/2, m.size());
    }
};
