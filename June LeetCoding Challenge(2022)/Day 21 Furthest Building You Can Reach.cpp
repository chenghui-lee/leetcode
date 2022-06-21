class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> s;
        int n = heights.size();
        
        for(int i=0; i<n-1; i++){
            int d = heights[i+1] - heights[i];
            if (d > 0){
                s.insert(d);
            }
            if (s.size() > ladders){ // prioritise ladders for those higher difference
                bricks -= *s.begin(); // use bricks for the smallest one
                s.erase(s.begin());
                if (bricks < 0) return i; // cant proceed to the next one
            }
        }
        return n-1;
    }
};
