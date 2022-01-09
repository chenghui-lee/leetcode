class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1},{-1,0}};
        int x= 0, y = 0, i = 0;
        
        for(auto ch : instructions){
            if (ch == 'R') i = (i + 1) % 4;
            else if (ch == 'L') i = (i + 3) % 4;
            else{
                x += dir[i][0], y += dir[i][1];
            }
        }
        return x == 0 && y == 0 || i > 0;
        // if the robot is not facing north (i==0), eventually it will come back to the origin
    }
};
