class Solution {
    private:
    int sumHelper(vector<vector<int>>& triangle,vector<vector<int>>& dp, int rowIndex, int colIndex){//2....1
        if(rowIndex == triangle.size()-1) return triangle[rowIndex][colIndex];//2....1
        if(rowIndex<0) return 0;//2
        if(dp[rowIndex][colIndex] != INT_MAX) return dp[rowIndex][colIndex];//2
        int partial1 = sumHelper(triangle, dp, rowIndex+1,colIndex);//1'
        int partial2 = sumHelper(triangle, dp, rowIndex+1,colIndex+1);
        return dp[rowIndex][colIndex] = triangle[rowIndex][colIndex]+min(partial1,partial2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),INT_MAX));
        return sumHelper(triangle, dp,0,0);
    }
};