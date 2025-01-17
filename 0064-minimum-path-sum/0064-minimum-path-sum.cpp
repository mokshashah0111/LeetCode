class Solution {
    private:
    int sumHelper(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row == 0 && col == 0){
            return grid[row][col];
        }
        if(row <0 || col<0) return INT_MAX;
        if(dp[row][col] != -1) return dp[row][col];
        int sum1 = sumHelper(row-1, col, grid, dp);
        int sum2 = sumHelper(row, col-1, grid, dp);
        dp[row][col] =  min(sum1,sum2)+grid[row][col];
        return dp[row][col];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowsize = grid.size();
        int colsize = grid[0].size();
        vector<vector<int>>dp(rowsize,vector<int>(colsize,-1));
        return sumHelper(rowsize-1,colsize-1,grid,dp);
    }
};