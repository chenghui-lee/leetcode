class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int idx = distance(arr.begin(), it);
        
        int left = idx-1, right = idx;
        vector<int> res;
        
        while(k > 0){
            if (left >=0 && right < n){
                if (x - arr[left] <= arr[right] - x) res.push_back(arr[left--]);
                else res.push_back(arr[right++]);
            }else if(left >= 0) res.push_back(arr[left--]);
            else res.push_back(arr[right++]);
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
