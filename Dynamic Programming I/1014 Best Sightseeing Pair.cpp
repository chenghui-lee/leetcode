class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int left = values[0], res = 0;
        
        for(int j=1; j<values.size(); j++){
            res = max(res, left + values[j] - j);
            left = max(left, values[j] + j); // prepare for next round,
            // since we will minus j+1 in the next round
        }
        return res;
    }
};
