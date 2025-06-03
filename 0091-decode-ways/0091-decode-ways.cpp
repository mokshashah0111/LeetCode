class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s.front()=='0') return 0;
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        dp[1]=1;

        for(int i =2; i<s.size()+1;i++){
            int first = s[i-1]-'0';
            int second = std::stoi(s.substr(i-2,2));

            if(first != 0){
                dp[i]+=dp[i-1];
            }
            if(second>=10 && second<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[s.size()];
    }
};