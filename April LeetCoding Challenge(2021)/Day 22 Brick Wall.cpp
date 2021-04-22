// Idea: count the number of edge, pick the most common (max frequency) then cut through it. result will be n - # most common edge
// https://leetcode.com/problems/brick-wall/discuss/137777/Java-Map-solution

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<int, int> m;
        
        int count = 0;
        for(auto row:wall){
            int sum = 0;
            for(int i=0; i<row.size()-1; i++){
                sum += row[i];
                m[sum]++;
                count = max(count, m[sum]);
            }
        }
        return n - count;
    }
};

// steps by steps sol, TLE at 77/85 tests
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(), sum = accumulate(wall[0].begin(), wall[0].end(), 0);
        vector<vector<int>> prefixSum(n);
        int res = n;
        for(int row=0; row<n;row++){
            prefixSum[row].push_back(wall[row][0]);
            for(int i=1; i<wall[row].size(); i++){
                prefixSum[row].push_back(prefixSum[row].back() + wall[row][i]);
            }
        }
        
        for(int i=1; i<=sum-1; i++){
            int temp = 0;
            for(int j=0; j<n; j++){
                for(auto col : prefixSum[j]){
                    if (col == i) break;
                    else if (col > i){
                        temp++;
                        break;
                    }
                }
            }
            res = min(res, temp);
        }
        return res;
    }
};
