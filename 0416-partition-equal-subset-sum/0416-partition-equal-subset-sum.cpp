class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int maxSum =0;
        for(int& num:nums){
            maxSum+= num;
        }

        if(maxSum %2) return false;
        vector<vector<bool>>dp(size+1, vector<bool>((maxSum/2)+1,false));
        for(int i=0;i<=size;i++){
            dp[i][0] = true;
        }
        for(int i=1;i<=size;i++){
            for(int j = 1; j<=maxSum/2;j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else dp[i][j]  = dp[i-1][j];
            }
        }
        return dp.back().back();
    }
};