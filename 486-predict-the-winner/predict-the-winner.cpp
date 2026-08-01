class Solution {
    int score(int left, int right, vector<int>& nums, vector<vector<int>>& dp){
        if(dp[left][right] != -1) return dp[left][right];
        if(left == right) return nums[left];

        int l = nums[left] - score(left+1, right, nums,dp);
        int r=  nums[right] - score(left, right-1, nums,dp);

        return dp[left][right] = max(l,r);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int rows = nums.size();
        vector<vector<int>>dp(rows, vector<int>(rows,-1));
        return score(0,rows-1, nums, dp) >=0;
    }
};