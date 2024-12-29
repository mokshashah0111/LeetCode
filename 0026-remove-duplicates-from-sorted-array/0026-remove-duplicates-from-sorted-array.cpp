class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr1 = 0;
        for(int ptr2 = 0 ; ptr2<nums.size();ptr2++){
            if(nums[ptr2] != nums[ptr1]){
                nums[ptr1+1] = nums[ptr2];
                ptr1++;
            }
        }
        return ptr1+1;
    }
};