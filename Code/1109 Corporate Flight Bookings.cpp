// https://leetcode.com/problems/corporate-flight-bookings/discuss/328856/JavaC%2B%2BPython-Sweep-Line
/*
booking = [i, j, k]
we need +k seats on i-th day, and don't need it when j+1 day.
So we can cummulative sum it.

*/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n+1, 0);
        for(auto b : bookings){
            res[b[0] -1] += b[2];
            res[b[1]] -= b[2];
        }
        for(int i=1; i<n; i++){
            res[i] += res[i-1];
        }
        return {res.begin(), res.end()-1};
    }
};
