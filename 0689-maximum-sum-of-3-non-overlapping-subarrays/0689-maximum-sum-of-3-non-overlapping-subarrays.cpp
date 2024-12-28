
class Solution {
private:
    int findIfPos(vector<int>& preSum, int k, int idx, int rem, vector<vector<int>>& dp) {
        if (rem == 0) return 0;
        if (idx >= (int)preSum.size()) return INT_MIN;
        if (dp[idx][rem] != -1) return dp[idx][rem];

        int take = preSum[idx] + findIfPos(preSum, k, idx + k, rem - 1, dp);
        int not_take = findIfPos(preSum, k, idx + 1, rem, dp);

        return dp[idx][rem] = max(take, not_take);
    }

    void findIdx(vector<int>& preSum, int k, int idx, int rem, vector<int>& result, vector<vector<int>>& dp) {
        if (rem == 0 || idx >= preSum.size()) return;
        int take = preSum[idx] + findIfPos(preSum, k, idx + k, rem - 1, dp);
        int not_take = findIfPos(preSum, k, idx + 1, rem, dp);
        if (take >= not_take) {
            result.emplace_back(idx);
            findIdx(preSum, k, idx + k, rem - 1, result, dp);
        } else {
            findIdx(preSum, k, idx + 1, rem, result, dp);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> result;
        int n = (int)nums.size() - k + 1;

        vector<int> preSum;
        int curSum = 0;
        int i = 0, j = 0;
        while (j < (int)nums.size()) {
            curSum += nums[j];
            if (j - i + 1 == k) {
                preSum.emplace_back(curSum);
                curSum -= nums[i];
                i++;
            }
            j++;
        }

        vector<vector<int>> dp(n, vector<int>(4, -1));
        findIdx(preSum, k, 0, 3, result, dp);
        return result;
    }
};