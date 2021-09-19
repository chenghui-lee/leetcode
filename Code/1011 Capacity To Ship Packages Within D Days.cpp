class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        // min we need the max(weights)
        // max we need the sum(weights)
        for(auto& x : weights){
            left = max(left, x);
            right += x;
        }
        
        
        while(left < right){
            int mid = left + (right - left) / 2;
            // can imagine this is bag, how many bag we need to fill up all the weights
            int need = 1, curCapacity = 0;
            for(auto& x : weights){
                // if the bag overweights, we put to next bag
                if (curCapacity + x > mid){
                    need++;
                    curCapacity = 0;
                }
                curCapacity += x;
            }
            if (need > days) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
