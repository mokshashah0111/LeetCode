class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev= prices[0];
        int ans = 0;
        for(int i = 1;i<prices.size();i++){
            ans = std::max(ans, prices[i]-prev);
            prev= std::min(prev,prices[i]);
        }
        return ans;
    }
};