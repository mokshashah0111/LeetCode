class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int maxLen =0;
        long long sum =0;
        unordered_map<int, int>mpp;

        for(int i = 0; i<nums.size();i++){
            sum+=nums[i];
            if(sum ==k){
                maxLen = max(maxLen,i+1);
            }
            long long rem = sum-k;
            if(mpp.find(rem) != mpp.end()){
                maxLen = max(maxLen, i-mpp[rem]);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return maxLen;
    }
};