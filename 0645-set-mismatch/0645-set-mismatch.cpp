class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = 0;
        int missing = 0;
        int actualSum = (nums.size()*(nums.size()+1))/2;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size();j++){
                if((nums[i] ^ nums[j]) == 0) duplicate = nums[i];
            }
            sum+=nums[i];
        }
        sum = sum-duplicate;
        return {duplicate,actualSum-sum};
    }
};