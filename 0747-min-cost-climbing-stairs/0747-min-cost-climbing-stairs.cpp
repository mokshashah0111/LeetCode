class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp = cost;
        dp.push_back(0);
        dp.push_back(0);
        for(int i = cost.size()-1;i>=0;i--){
            dp[i] = cost[i]+std::min(dp[i+1],dp[i+2]);
        }
        for(int nums:dp){
            std::cout<<nums<<" ";
        }
        return std::min(dp[0],dp[1]);
    }
};