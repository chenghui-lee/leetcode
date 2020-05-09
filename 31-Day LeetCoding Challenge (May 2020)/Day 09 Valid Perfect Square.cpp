// Since we are not allowed to use the build in sqrt function
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0){
            return false;
        }
        if (num == 1){
            return true;
        }
        int left = 1;
        int right = num/2;
        while (left<=right){
            long long mid = left + (right-left)/2;
            if (mid*mid == num){
                return true;
            }else if (mid*mid > num){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
        
    }
};
