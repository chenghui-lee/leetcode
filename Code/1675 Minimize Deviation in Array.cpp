/*

Idea: Make all the odd numbers to even by x2, then decrease the largest number until it become odd numbers.
Concept: For each numbers, we only can either x2 or /2 but not both, because a odd number when x2 will get even number 
and when divided by 2, will get back the same result.

*/

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
