class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double x1 = coordinates[0][0];
        double y1 = coordinates[0][1];
        double x2 = coordinates[1][0];
        double y2 = coordinates[1][1];
        double gradient = (y2-y1)/(x2-x1);
        
        for (int i=1;i<coordinates.size();i++){
            double xc = coordinates[i][0];
            double yc = coordinates[i][1];
            
            if ((yc-y1)/(xc-x1) != gradient)
                return false;
            
        }
        return true;
    }
};
