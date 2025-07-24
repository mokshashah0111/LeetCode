class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // dp[0][0] = word1[0] == word2[0];

        for(int i =1;i<=m;i++){
            for(int j =1; j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        int res = m-dp[m][n] + n- dp[m][n];
        return res;
    }
};