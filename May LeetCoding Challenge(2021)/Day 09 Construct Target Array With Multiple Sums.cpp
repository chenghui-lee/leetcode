// https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/510256/JavaC%2B%2BPython-Backtrack-OJ-is-wrong

class Solution {
public:
    
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto x:target){
            sum += x;
            pq.push(x);
        }
        
        while(true){
            long long temp = pq.top(); pq.pop();
            sum -= temp;
            
            if (temp == 1 || sum == 1) return true;
            if (sum > temp || sum == 0 || temp % sum == 0) return false;
            temp %= sum;
            sum += temp;
            pq.push(temp);
        }
       
    }
};
