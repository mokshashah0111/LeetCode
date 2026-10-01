class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int smaller = 0;

        for(int i =0; i<size;i++){
            if(nums[i] == 0){
                swap(nums[i],nums[smaller++]);
            }
        }
        int larger = size-1;
        for(int i = size-1;i >=0;i--){
            if(nums[i] ==2){
                swap(nums[i], nums[larger--]);
            }
        }
    }
};