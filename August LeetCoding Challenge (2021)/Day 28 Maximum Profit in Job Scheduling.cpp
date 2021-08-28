// https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409009/JavaC%2B%2BPython-DP-Solution
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs;
        
        for(int i=0; i<n; i++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});    
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}}; // [endtime, profit] ~ max profit at time 
        for(auto& job : jobs){
            auto cur = prev(dp.upper_bound(job[1]))->second + job[2]; // previous job profit + cur profit
            if (cur > dp.rbegin()->second){ // if profit larger than last job 
                dp[job[0]] = cur;
            }
        }
        return dp.rbegin()->second;
    }
};
