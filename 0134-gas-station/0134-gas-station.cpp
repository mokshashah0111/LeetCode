class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int startIndex = 0;
        int currentGas = 0;
        for(int i = 0; i<cost.size();i++){
            totalGas+= gas[i];
            totalCost += cost[i];
        }
        if(totalGas < totalCost) return -1;
        for(int i = 0; i<cost.size();i++){
            currentGas+= gas[i] -cost[i];
            if(currentGas <0){
                startIndex=i+1;
                currentGas=0;
            }
        }
        return startIndex;
    }
};