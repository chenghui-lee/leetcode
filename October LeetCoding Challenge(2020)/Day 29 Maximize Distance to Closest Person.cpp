class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int last = -1, res = 0;
        for(int i=0; i<seats.size(); i++){
            if (seats[i] == 1){
                if (last < 0){ // to capture the edge case where first is zero
                    res = i;
                }else{
                    res = max(res, (int)((i - last)/2));
                }
                last = i;
            }
        }
        res = max(res, (int)seats.size() - last - 1); // to capture the edge case where last is zero
        return res;
    }
};
