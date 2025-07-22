class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        using T = tuple<long long,int,int>;
        priority_queue<T,vector<T>,greater<T>>minHeap;
        vector<long long>dp(n);
        dp[0] = 1;
        for(int i =0; i<primes.size();i++){
            minHeap.emplace(primes[i],i,0);
        }

        for (int i = 1; i < n; ++i) {
            dp[i] = get<0>(minHeap.top());

            while (!minHeap.empty() && get<0>(minHeap.top()) == dp[i]) {
                auto [val, primeIdx, idx] = minHeap.top();
                minHeap.pop();
                minHeap.emplace((long long)dp[idx + 1] * primes[primeIdx], primeIdx, idx + 1);
            }
        }
        return (int)dp.back();
    }
};