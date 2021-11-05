class Solution {
public:
    int arrangeCoins(int n) {
        long low = 0, high = n;
        long sum = 0;
        
        while(low <= high){
            long mid = low + (high - low)/2;
            sum = mid*(mid+1)/2;
            if (sum == n){
                return (int)mid;
            }else if (sum > n) high = mid - 1;
            else low = mid + 1;
        }
        return (int)high;
    }
};
