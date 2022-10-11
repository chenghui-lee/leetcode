class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstNum = INT_MAX, secondNum = INT_MAX;
        for(int x : nums) {
            if (x <= firstNum) firstNum = x;
            else if (x <= secondNum) secondNum = x;
            else return true; // larger than both the prev num
        }
        return false;
    }
};
