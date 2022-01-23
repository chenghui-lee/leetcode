class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        
        queue<int> q;
        
        for(int i=1; i<=9; i++){
            q.push(i);
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            if(cur >= low && cur <= high){
                res.push_back(cur);
            }
            else if (cur > high) break;
            
            int lastDigit = cur % 10;
            if (lastDigit < 9){
                q.push(cur * 10 + (lastDigit+1));
            }
        }
        return res;
    }
};
