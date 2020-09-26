class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int until, res = 0;
        
        if (timeSeries.size() == 0 || duration == 0) return 0;
        until = timeSeries[0] + duration -1;
        
        for(int i=1; i<timeSeries.size(); i++){
            if (timeSeries[i] > until){
                res += duration;                
            }else{
                res += timeSeries[i] - timeSeries[i-1];
            }
            until = timeSeries[i] + duration -1;
        }
        res += duration;
        return res;
    } 
};

// same concept, cleaner
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0 || duration == 0) return 0;
        int res = 0;
        for(int i=1; i<timeSeries.size(); i++){
            res += min(duration, timeSeries[i] - timeSeries[i-1]);
        }
        res += duration;
        return res;
    }
