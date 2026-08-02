class Solution {
    int score(vector<int>& piles, vector<vector<int>>& dp, int left, int right){
        if(dp[left][right] != -1) return dp[left][right];
        if(left == right) return piles[left];

        int l = piles[left]- score(piles, dp,left+1, right);
        int r = piles[right]- score(piles, dp,left, right-1);

        return dp[left][right] = max(l,r);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int rows = piles.size();
        vector<vector<int>>dp(rows, vector<int>(rows,-1));
        return score(piles,dp,0,rows-1) >=0;
    }
};