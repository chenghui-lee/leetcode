class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        vector<int> res;
        
        for(int i=1; i<=9; i++){
            q.push(i);
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            if (cur >= low && cur <= high){
                res.push_back(cur);
            }
            if (cur > high) break;
            int num = cur % 10;
            
            if (num < 9){ // still can add digit behind it
                q.push(cur*10 + (num+1));
            }
        }
        return res;
    }
};
