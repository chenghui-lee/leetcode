class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(auto& x : nums){
            if (x%2) s.insert(x*2);
            else s.insert(x);
        }
        int res = *s.rbegin() - *s.begin();
        
        while(*s.rbegin() %2 == 0){
            s.insert(*s.rbegin()/2);
            s.erase(*s.rbegin());
            res = min(res, *s.rbegin() - *s.begin());
        }
        return res;
    }
};
