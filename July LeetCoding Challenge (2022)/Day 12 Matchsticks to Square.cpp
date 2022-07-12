class Solution {
public:
    
    bool dfs(vector<int>& matchsticks, vector<int>& temp, int index, long target){
        if (index == matchsticks.size()) return true;
        
        for(int i=0; i<4; i++){
            if (matchsticks[index] + temp[i] <= target){
                temp[i] += matchsticks[index];
                if (dfs(matchsticks, temp, index+1, target)) return true;
                temp[i] -= matchsticks[index];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        if (sum % 4) return false;
        vector<int> temp(4);
        return dfs(matchsticks, temp, 0, sum / 4);
    }
};
