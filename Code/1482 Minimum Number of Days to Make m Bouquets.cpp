class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (m * k > bloomDay.size()) return -1;
        
        int left = INT_MAX, right = 0;
        // max we need max(bloomDay)
        // min we need min(bloomDay)
        for(auto& x : bloomDay){
            left = min(left, x);
            right = max(right, x);
        }
        // ... search btwn left and right
        while(left < right){
            int mid = left + (right - left) / 2;
            int bouCompleted = 0, curCollected = 0;
            for(auto& x : bloomDay){
                if (x <= mid){
                    curCollected++;
                }else{
                    curCollected = 0;
                }
                if (curCollected == k){
                    bouCompleted++;
                    curCollected = 0;
                }
            }
            
            if (bouCompleted >= m) right = mid;
            else left = mid+1;
        }
        return left;
        
    }
};
