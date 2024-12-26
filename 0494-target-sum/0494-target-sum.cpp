class Solution {
public:
    void targetHelper(vector<int>& nums, int target, int index, int sum, int& count){
        if(index == nums.size()){
            if(sum == target) count++;
            return;
        }
        // sum += nums[index];
        targetHelper(nums, target, index+1, sum+nums[index], count);
        // sum -= nums[index];
        nums[index] = -nums[index];
        targetHelper(nums, target, index+1, sum+nums[index], count);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int count = 0;
        targetHelper(nums, target, 0, sum, count);
        return count;
    }
};