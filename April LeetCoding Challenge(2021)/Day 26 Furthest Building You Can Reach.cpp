/*
Heap / multiset store k height difference that we need to use ladders.
Each move, if the height difference d > 0,
we push d into the priority queue pq.
If the size of queue exceed ladders,
it means we have to use bricks for one move.
Then we pop out the smallest difference, and reduce bricks.
If bricks < 0, we can't make this move, then we return current index i.
If we can reach the last building, we return A.length - 1

*/

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
            if (s.size() > ladders){
                bricks -= *s.begin();
                s.erase(s.begin());
                if (bricks < 0) return i;
            }
        }
        return n-1;
    }
};
