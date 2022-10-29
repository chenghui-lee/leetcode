/*
Idea: 
Plants grow independently and continuously. Only the plant time is changable
Assuming the plant grows before planting. Sort the plants by growtime, then plus all the plant time


*/
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v; // {growtime, planttime}
        for(int i=0; i<plantTime.size(); i++){
            v.push_back({growTime[i], plantTime[i]});
        }
        sort(v.begin(), v.end());
        int res = 0;
        for(auto [g, p] : v){
            res = max(res, g) + p; // check if the prev growTime is enough to cover the current plant, if not enough, use the current plant growTime
        }
        return res;
    }
};
