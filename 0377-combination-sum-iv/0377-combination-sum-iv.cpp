class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long>combinations(target+1,0);
        combinations[0] = 1;
        for(int i =1 ; i<=target;i++){
            for(int score: nums){
                if(i>=score){
                    combinations[i]+= combinations[i-score];
                }
            }
            if (combinations[i] > INT_MAX) combinations[i] = INT_MAX;

        }
        return combinations[target];
    }
};