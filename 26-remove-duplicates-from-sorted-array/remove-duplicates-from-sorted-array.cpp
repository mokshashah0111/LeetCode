class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int writeIndex =1;
        for(int i =1;i<nums.size();i++){
            if(nums[writeIndex-1] != nums[i]){
                nums[writeIndex++] = nums[i];
            }
        }
        return writeIndex;
    }
};