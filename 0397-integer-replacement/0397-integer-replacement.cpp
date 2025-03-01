class Solution {
    private:
    int replacementHelper(unordered_map<long long,int>& dp, long long index){

        if(index ==1) return 0;
        if(dp.find(index) != dp.end()) return dp[index];
        if(index%2 == 0){
            dp[index] = replacementHelper(dp, index/2) +1;
        }
        else{
            dp[index] = min(replacementHelper(dp, index-1) , replacementHelper(dp, index+1))+1;
        }
        return dp[index];
    }
public:
    int integerReplacement(int n) {
        // if(n == INT_MAX) n -=1;
        unordered_map<long long, int>dp;
        return replacementHelper(dp,n);
    }
};