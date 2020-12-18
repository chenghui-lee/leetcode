class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, big = INT_MAX;
        for(auto x : nums){
            if (x <= small) small = x;
            else if (x <= big) big = x;
            else return true;
        }
        return false;
    }
};
