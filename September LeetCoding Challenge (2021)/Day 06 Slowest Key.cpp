class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char curKey = keysPressed[0];
        int curLongest = releaseTimes[0];
        
        for(int i=1; i<keysPressed.size(); i++){
            if (releaseTimes[i] - releaseTimes[i-1] >= curLongest){
                if (releaseTimes[i] - releaseTimes[i-1] == curLongest){
                    curKey = max(curKey, keysPressed[i]);
                }
                else curKey = keysPressed[i];
                curLongest = releaseTimes[i] - releaseTimes[i-1];
            }
        }
        return curKey;
    }
};
