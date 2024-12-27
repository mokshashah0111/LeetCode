class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int prev = values[0];

        for(int j = 1;j<values.size();j++){
            ans = std::max(ans, prev+values[j]-j);
            prev = std::max(prev,values[j]+j);
        }
        return ans;
    }
};