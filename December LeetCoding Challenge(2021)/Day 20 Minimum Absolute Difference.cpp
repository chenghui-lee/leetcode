class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int curMin = INT_MAX;
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        for(int i=1; i<arr.size(); i++){
            if (arr[i] - arr[i-1] < curMin){
                curMin = arr[i] - arr[i-1];
                res.clear();
                res.push_back({arr[i-1], arr[i]});
            }else if (arr[i] - arr[i-1] == curMin){
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};
