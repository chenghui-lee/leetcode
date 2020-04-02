class Solution {
public:
bool isHappy(int n) {
    int temp = n, k = 10,sum = 0;
    while (k--){
        while (temp!=0){
        	sum += pow(temp%10,2);
        	temp /= 10;
        }
        if (sum == 1)
        	return true;
        temp = sum;
        sum = 0;
    }
    return false;
}
};
// runtime 0ms
