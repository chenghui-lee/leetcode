class Solution {
public:
    
    int subarraySum(vector<int>& arr, int k){
        unordered_map<int, int> m;
        int sum = 0, res  = 0;
        
        for(auto x : arr){
            sum += x;
            if (sum == k) res++;
            if (m[sum - k]) res += m[sum-k];
            m[sum]++;
        }
        
        return res;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> arr(m);
        int res = 0;
        
        for(int i=0; i<n; i++){ // starting col
            fill(arr.begin(), arr.end(), 0);
            for(int j=i; j<n; j++){ // ending col    
                for(int row=0; row<m; row++){ // for every row
                    arr[row] += matrix[row][j];
                }
                res += subarraySum(arr, target);
            }
        }
        return res;
    }
};
