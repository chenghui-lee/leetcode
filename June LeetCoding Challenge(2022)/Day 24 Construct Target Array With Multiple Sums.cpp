class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq; // max heap
        long sum = 0;
        
        for(int x : target){
            sum += x;
            pq.push(x);
        }
        while(true){
            int maxElement = pq.top();
            pq.pop();
            sum -= maxElement; // [max, a1, a2, ... an], sum = sum(a1,an)
            if (maxElement == 1  // all 1
                || sum == 1) return true; // [max, 1] will always be true
            
            /*
            mod is used to accelerate the minus process, where the max element 
            remains the biggest after many operation
            
            no mod
            [max, a1, a2, an] -> [max - (a1+a2+an), a1, a2, an] -> [max - 2*(a1+a2+an), a1, a2, an] -> ... -> [max - n*(a1+a2+an), a1, a2, an]
            
            the max actually can be represented as max = max % (a1+a2+an)
            
            with mod
            [max, a1, a2, an] -> [max % (a1+a2+an), a1, a2, an] -> [no_longer_max, a1, a2, an]
            
            */
            if (maxElement < sum || sum == 0 || maxElement % sum == 0) return false; // sum == 0 is for array length of 1, for example [1] [2]
            
            maxElement %= sum;
            sum += maxElement;
            pq.push(maxElement);
        }
    }
};
