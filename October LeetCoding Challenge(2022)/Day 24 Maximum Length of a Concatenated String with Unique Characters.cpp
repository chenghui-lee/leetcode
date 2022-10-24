class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for(auto& a : arr){
            bitset<26> cur;
            for(auto& ch : a) cur.set(ch - 'a');
            if (cur.count() < a.size()) continue;
            
            for(int i=dp.size()-1; i>=0; i--){
                bitset<26> a = dp[i];
                if ((a & cur).any()) continue;
                dp.push_back(a | cur);
                res = max(res, (int)(a.count() + cur.count()));
            }
        }
        
        return res;
    }
};
