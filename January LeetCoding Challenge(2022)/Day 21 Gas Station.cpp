class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumCost = 0, sumGas = 0, bal = 0, start = 0;
        
        for(int i=0; i<cost.size(); i++){
            sumCost += cost[i];
            sumGas += gas[i];
            
            bal += (gas[i] - cost[i]);
            if (bal < 0){ // try to start from the next one
                start = i+1;
                bal = 0;
            }
        }
        if (sumGas >= sumCost) return start;
        return -1;
    }
};
