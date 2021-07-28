// https://leetcode.com/problems/beautiful-array/discuss/186679/Odd-%2B-Even-Pattern-O(N)
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};
        while(res.size() < n){
            vector<int> temp;
            for(auto x : res){
                if (x * 2 - 1 <= n) temp.push_back(x*2-1);
            }
            for(auto x : res){
                if (x * 2 <= n) temp.push_back(x*2);
            }
            res = temp;
        }
        return res;
    }
};
