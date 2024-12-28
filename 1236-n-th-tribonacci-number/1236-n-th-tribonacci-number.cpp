class Solution {
    private:
    int tribonacciHelper(int n, vector<int>& dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n] != -1) return dp[n];
        else dp[n] = tribonacciHelper(n-1,dp)+tribonacciHelper(n-2, dp) + tribonacciHelper(n-3, dp);
        return dp[n];
    }
public:
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return tribonacciHelper(n, dp);
    }
};