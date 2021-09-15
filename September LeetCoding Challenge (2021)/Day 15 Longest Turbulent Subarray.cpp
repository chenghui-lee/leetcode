class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), inc = 1, dec = 1, res = 1;
        // inc = length ends with 2 inc num
        // dec = ends with 2 dec num
        for(int i=1; i<n; i++){
            if (arr[i] > arr[i-1]){
                inc = dec + 1;
                dec = 1;
            }else if (arr[i] < arr[i-1]){
                dec = inc + 1;
                inc = 1;
            }else{
                dec = inc = 1;
            }
            res = max(res, max(inc, dec));
        }
        return res;
    }
};
