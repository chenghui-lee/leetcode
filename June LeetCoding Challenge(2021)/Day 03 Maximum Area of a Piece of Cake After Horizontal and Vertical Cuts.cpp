class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        
        int diff1 = horizontalCuts[0];
        for(int i=1; i<horizontalCuts.size(); i++){
            diff1 = max(diff1, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        int diff2 = verticalCuts[0];
        for(int i=1; i<verticalCuts.size(); i++){
            diff2 = max(diff2, verticalCuts[i] - verticalCuts[i-1]);
        }
        return (long)diff1 * diff2 % 1000000007;;
    }
};
