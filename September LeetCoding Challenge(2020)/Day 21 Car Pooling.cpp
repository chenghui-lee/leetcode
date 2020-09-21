class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> time(1001, 0);
        int place = capacity;
        for(int i=0; i<trips.size(); i++){
            time[trips[i][1]] += trips[i][0];
            time[trips[i][2]] -= trips[i][0];
        }
        for(int i=0; i<time.size(); i++){
            place -= time[i];
            if (place < 0) return false;
        }
        return true;
    }
};
