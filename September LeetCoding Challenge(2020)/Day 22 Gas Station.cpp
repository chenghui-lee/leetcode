class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0, sumCost = 0, bal = 0, start = 0;
        
        for(int i=0; i<cost.size(); i++){
            sumGas += gas[i];
            sumCost += cost[i];
            bal += gas[i] - cost[i];
            if (bal < 0){
                bal = 0;
                start = i+1;
            }
        }
        if(sumGas >= sumCost) return start;
        else return -1;
    }
};
