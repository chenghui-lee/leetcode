class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(int x : nums){
            if (x % 2 == 1) s.insert(x * 2); // we want difference as low as possible, so the min also must as big as possible, the largest one doesnt matter because we can /2 later if we want
            else s.insert(x);
        }
        int res = *s.rbegin() - *s.begin();
        
        while(*s.rbegin() % 2 == 0){
            s.insert(*s.rbegin() / 2);
            s.erase(*s.rbegin());
            res = min(res, *s.rbegin() - *s.begin());
        }
        return res;
    }
};
