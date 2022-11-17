class Solution {
public:

    int intercept(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
        int xRange = 0;
        int yRange = 0;
        if (bx1 >= ax1 && bx1 <= ax2){
            xRange = min(ax2, bx2) - bx1;
        } else if (ax1 >= bx1 && ax1 <= bx2){
            xRange = min(ax2, bx2) - ax1;
        }

        if (ay1 >= by1 && ay1 <= by2){
            yRange = min(by2, ay2) - ay1;
        }else if (by1 >= ay1 && by1 <= ay2){
            yRange = min(ay2, by2) - by1;
        }

        return xRange * yRange;
    }

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int interceptarea = intercept(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        return area1 + area2 - interceptarea;
    }
};
