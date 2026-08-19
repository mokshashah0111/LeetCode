class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1 || nums.size()==0) return nums.size();
        int writeIndex =1;
        for(int i =1; i<nums.size();i++){
            if(nums[i] != nums[i-1]){
                nums[writeIndex++] = nums[i];
            }
        }
        return writeIndex;
    }
};