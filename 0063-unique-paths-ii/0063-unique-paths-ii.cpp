class Solution {
    private:
    int pathHelper(int row, int col, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(grid[row][col] == 1) return 0;
        if(row==grid.size()-1 && col == grid[0].size()-1) return 1;
        if(row>=grid.size() || col>= grid[0].size()) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int right=0, left =0;
        if(col+1 < grid[0].size()&& grid[row][col+1] != 1){
            right = pathHelper(row, col+1, grid, dp);
        }
        if(row+1 < grid.size() && grid[row+1][col] != 1){
            left = pathHelper(row+1, col, grid, dp);
        }
        dp[row][col] = left+right;
        return dp[row][col];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rowsize = obstacleGrid.size();
        int colsize = obstacleGrid[0].size();

        vector<vector<int>>dp(rowsize,vector<int>(colsize,-1));
        return pathHelper(0, 0, obstacleGrid, dp);
    }
};