        // For each i, we have 3 options: 1. remove all chars from left
        // 2. remove all chars from right and 3. remove this char and the rest 
        // of i-1 or i+1. 
        // So lets do 2 loops, one for L2R pass and one for R2L pass
        // for case 3. L2R pass dp1[i] indicates min operations needed if we only remove
        // cars from the left, and R2L pass dp2[i] indicates min operations needed if we 
        // only remove cars from the right uptil and including i. Then adding dp1[i] + dp2[i+1]
        // should give us the answer:
        
class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> left(n, 0); 
        left[0] = s[0] == '1' ? 1 : 0;
        
        for(int i=1; i<n; i++){
            if (s[i] == '1'){ // min(prev + remove cur, remove from left to i)
                left[i] = min(left[i-1] + 2, i+1);
            }else{
                left[i] = left[i-1];
            }
        }
        
        vector<int> right(n, 0);
        right[n-1] = s[n-1] == '1' ? 1 : 0;
        for(int i=n-2; i>=0; i--){
            if (s[i] == '1'){
                right[i] = min(right[i+1] + 2, n-i);
            }else{
                right[i] = right[i+1];
            }
        }
        
        int res = INT_MAX;
        res =  min(left[n-1],right[0]); // remove from the left to the end, or remove from the right to 1st one
        
        for(int i=0; i<n-1; i++){
            res = min(res, left[i] + right[i+1]); // to-do : understand this
        }
        
        return res;
    }
};
