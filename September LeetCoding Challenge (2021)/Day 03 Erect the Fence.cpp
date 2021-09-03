// convex hull
// jarvis algorithm
class Solution {
public:
    
    int orientation(vector<int>& p, vector<int>& q, vector<int>& r){
        // 0 = colinear
        // positive = clockwise
        // neg = counter-clockwise
        // return (q.y-p.y) * (r.x-q.x) - (q.x-p.x) * (r.y-q.y);
        return (q[1]-p[1]) * (r[0]-q[0]) - (q[0]-p[0]) * (r[1]-q[1]);
    }
    
    // check if point i is inbetween point p and q
    bool inBetween(vector<int>& p, vector<int>& i, vector<int>& q){
        bool x = i[0] >= min(p[0], q[0]) && i[0] <= max(p[0], q[0]);
        bool y = i[1] >= min(p[1], q[1]) && i[1] <= max(p[1], q[1]);
        return x && y;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        
        if (trees.size() <= 3) return trees;
        
        int leftmost = 0, n = trees.size();
        
        for(int i=1; i<n; i++){
            if (trees[i][0] < trees[leftmost][0]){
                leftmost = i;
            }
        }
        
        set<vector<int>> hulls;
        int p = leftmost;
        
        do{
            hulls.insert(trees[p]);
            int q = (p+1) % n;
            
            for(int i=0; i<n; i++){
                // if counter clockwise
                if (orientation(trees[p], trees[i], trees[q]) < 0){
                    q = i;
                }
            }
            // check for points that are collinear with pq, and in between them
            for(int i=0; i<n; i++){
                if (i != p && i != q && orientation(trees[p], trees[q], trees[i]) == 0
                    && inBetween(trees[p], trees[i], trees[q])){
                    hulls.insert(trees[i]);
                }
            }
            
            p = q;
            
        }while(p != leftmost);
        
        return vector<vector<int>>(hulls.begin(), hulls.end());
    }
};
