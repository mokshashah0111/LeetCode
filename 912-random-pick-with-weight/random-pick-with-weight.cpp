class Solution {
private:
    vector<int> prefixSums;
    int totalSum;

public:
    Solution(vector<int>& w) {
        totalSum = 0;
        for (int weight : w) {
            totalSum += weight;
            prefixSums.push_back(totalSum);
        }
    }
    
    int pickIndex() {
        // Generate a random number from 1 to totalSum
        int target = rand() % totalSum + 1;
        // Find the first element greater than or equal to target
        auto it = lower_bound(prefixSums.begin(), prefixSums.end(), target);
        return distance(prefixSums.begin(), it);
    }
};
