class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<vector<int>> s;
        int n = temperatures.size();
        vector<int> res(n, 0);
        
        for(int i=0; i<n; i++){
             if (s.empty() || temperatures[i] <= s.back()[0]){
                 s.push_back({temperatures[i], i});
             }else{
                 while(!s.empty() && temperatures[i] > s.back()[0]){
                     res[s.back()[1]] = i - s.back()[1];
                     s.pop_back();
                 }
                 s.push_back({temperatures[i], i});
             }
        }
        return res;
    }
};
