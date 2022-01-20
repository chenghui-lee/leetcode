class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        
        while(l < r){
            int mid = (l+r)/2;
            int total = 0;
            for(auto p : piles){
                total += ceil((double) p / mid);
            }
            if (total > h){ // need to increase k
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};
