class Solution {
public:
    /*
    Check for the count of digit for the power of 2
    
    */
    bool reorderedPowerOf2(int N) {
        if (N == 0) return true;
        
        vector<int> arr(10);
        while(N){
            int digit = N % 10;
            arr[digit]++;
            N /= 10;
        }
        
        for(long i=0; i<31; i++){
            long k = 1 << i;
            vector<int> temp(10);
            while(k){
                int digit = k % 10;
                temp[digit]++;
                k /= 10;
            }
            if (temp == arr) return true;
        }
        return false;
    }
};
