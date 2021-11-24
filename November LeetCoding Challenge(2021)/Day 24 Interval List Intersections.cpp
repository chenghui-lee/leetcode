class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        for(auto x : secondList){
            firstList.push_back(x);
        }
        sort(firstList.begin(), firstList.end());
        vector<vector<int>> res;
        
        int prevStart = firstList[0][0], prevEnd = firstList[0][1];
        
        for(int i=1; i<firstList.size(); i++){
            if (firstList[i][0] >= prevStart && firstList[i][0] <= prevEnd){
                res.push_back({firstList[i][0], min(firstList[i][1], prevEnd)});
            }
            prevStart = firstList[i][0], prevEnd = max(prevEnd, firstList[i][1]);
        }
        return res;
    }
};
