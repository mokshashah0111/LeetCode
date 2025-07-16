class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        vector<int>dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i =1;i<nums.size();i++){
            dp[i] = max(dp[i-1],nums[i]+i);
        }

        int index =0;

        while(index<nums.size()-1){
            jumps++;
            index = dp[index];
        }
        return jumps;
    }
};
