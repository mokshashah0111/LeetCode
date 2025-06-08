class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int writeIndex =  2;
        for(int i =2; i<nums.size();i++){
            if(nums[writeIndex-2] !=  nums[i]) nums[writeIndex++] = nums[i];
        }
        return writeIndex;   
    }
};