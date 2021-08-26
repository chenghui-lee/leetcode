class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> arr; // [x, height]
        for(auto building : buildings){
            arr.push_back({building[0], -building[2]}); // opening
            arr.push_back({building[1], building[2]}); // closing
        }
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        
        multiset<int> heights;
        heights.insert(0);
        
        int prevHeight = 0;
        for(auto b : arr){
            if (b[1] < 0){ // opening
                heights.insert(-b[1]);
            }else{ // closing
                heights.erase(heights.find(b[1]));
            }
            int curMax = *heights.rbegin();
            if (curMax != prevHeight){
                res.push_back({b[0], curMax});
                prevHeight = curMax;
            }
        }
        return res;
    }
};
