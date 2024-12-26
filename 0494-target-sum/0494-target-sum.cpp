class Solution {
public:
    void targetHelper(vector<int>& nums, int target, int index, int& count){
        if(index == nums.size()){
            if(target == 0) count++;
            return;
        }
        targetHelper(nums, target-nums[index], index+1, count);
        nums[index] = -nums[index];
        targetHelper(nums, target-nums[index], index+1, count);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        targetHelper(nums, target, 0, count);
        return count;
    }
};