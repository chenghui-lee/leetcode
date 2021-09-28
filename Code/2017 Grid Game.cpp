//https://leetcode.com/problems/grid-game/discuss/1486340/C%2B%2BJavaPython-Robot1-Minimize-TopSum-and-BottomSum-of-Robot-2-Picture-Explained
// dp cant work, because it cannot guarantee the robot 2 is min
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topsum = 0, bottomsum = 0, res = LLONG_MAX;
        topsum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        
        for(int i=0; i<grid[0].size(); i++){
            topsum -= grid[0][i];
            res = min(res, max(topsum, bottomsum));
            bottomsum += grid[1][i];
        }
        return res;
    }
};
