class Solution {
    private:
    int helper(string word1, int index1,string word2, int index2, vector<vector<int>>& dp){
        if(index1<0) return index2+1;
        else if(index2<0) return index1+1;
        if(dp[index1][index2] ==-1){
            if(word1[index1] == word2[index2]){
                return helper(word1, index1-1, word2,index2-1,dp);
            }
            else{
                int sum1 = helper(word1, index1, word2,index2-1,dp);
                int sum2 = helper(word1, index1-1,word2,index2-1,dp);
                int sum3 = helper(word1,index1-1, word2, index2,dp);
                int minimum = min(sum1,sum2);
                dp[index1][index2] = 1+ min(minimum,sum3); 
            }
        }
        return dp[index1][index2];
    }
public:
    int minDistance(string word1, string word2) {
        int length1 = word1.size();
        int length2 = word2.size();

        vector<vector<int>>dp(length1,vector<int>(length2,-1));
        return helper(word1,length1-1,word2, length2-1, dp);
    }
};