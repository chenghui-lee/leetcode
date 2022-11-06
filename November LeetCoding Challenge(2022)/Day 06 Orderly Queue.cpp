class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        
        deque<char> dq(s.begin(), s.end());
        auto res = dq;
        // rotate the string
        for(int i=1; i<s.size(); i++){
            dq.push_back(dq[0]);
            dq.pop_front();
            res = min(res, dq);
        }
        return string(res.begin(), res.end());
    }
    
};
