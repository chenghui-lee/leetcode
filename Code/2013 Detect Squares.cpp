// https://leetcode.com/contest/weekly-contest-259/problems/detect-squares/
// 1st solution, fix the diagonal point, then find the rest 2
class DetectSquares {
public:
    int cnt[1001][1001] = {};
    vector<pair<int, int>> points;
    DetectSquares() {
        
    }
    
    void add(vector<int> p) {
        cnt[p[0]][p[1]]++;
        points.push_back({p[0], p[1]});
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1], res = 0;
        
        for(auto& [x3, y3] : points){
            if (abs(x1 - x3) == 0 || abs(x1 - x3) != abs(y1 - y3)){
                continue;
            }
            res += cnt[x1][y3] * cnt[x3][y1];
        }
        
        return res;
    }
};

// 2nd solution, fix the point having same x, then find the rest 2, either on the left, or right side of both of the points
class DetectSquares {
public:
    unordered_map<int, vector<int>> xToY;
    map<pair<int, int>, int> cnt;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        xToY[point[0]].push_back(point[1]);
        cnt[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1], res = 0;
        for(auto& y2 : xToY[x1]){
            if (y1 == y2) continue;
            int sideLen = abs(y1 - y2);
            
            // if the other 2 points on the left
            int x3 = x1 - sideLen, y3 = y1;
            int x4 = x1 - sideLen, y4 = y2;
            res += cnt[{x3, y3}] * cnt[{x4,y4}];
            
            // if the other 2 points on the right
            x3 = x1 + sideLen, y3 = y1;
            x4 = x1 + sideLen, y4 = y2;
            res += cnt[{x3, y3}] * cnt[{x4,y4}];
        }
        
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
