class Solution {
public:
    int dp[101][101][21]; // houses, neighborhood, prev house colour
    int INF = 1e9;
    
    int helper(vector<int>& houses, vector<vector<int>>& cost, int targetCount, int curIndex, int neighborhoodCount, int prevHouseColour){
        if (curIndex == houses.size()){
            if (neighborhoodCount == targetCount){
                return 0;
            }
            return INF;
        }
        if (neighborhoodCount > targetCount) return INF;
        // if visited before
        if (dp[curIndex][neighborhoodCount][prevHouseColour] != -1){
            return dp[curIndex][neighborhoodCount][prevHouseColour];
        }
        int minCost = INF;
      
        if (houses[curIndex] > 0){ // this house is already painted, proceed witah the next house
            minCost = helper(houses, cost, targetCount, curIndex + 1, neighborhoodCount + (houses[curIndex] != prevHouseColour), houses[curIndex]);
        }else{ // try every possible colour and find the min
            for(int i=0; i<cost[0].size(); i++){
                int newNeighborhoodCount = neighborhoodCount + ((i+1) != prevHouseColour); 
                int curCost = cost[curIndex][i] + helper(houses, cost, targetCount, curIndex + 1, newNeighborhoodCount, i+1);
                minCost = min(minCost, curCost);
            }
        }
        return dp[curIndex][neighborhoodCount][prevHouseColour] = minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int res = helper(houses, cost, target, 0,0,0);
        return res == INF? -1 : res;
    }
};
