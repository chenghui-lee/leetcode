class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losecount;
        unordered_set<int> player;
        for(auto m : matches){
            losecount[m[1]]++;
            player.insert(m[0]);
            player.insert(m[1]);
        }
        vector<vector<int>> res(2);
        for(int p : player){
            if (losecount[p] == 0) res[0].push_back(p);
            else if (losecount[p] == 1) res[1].push_back(p);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};
