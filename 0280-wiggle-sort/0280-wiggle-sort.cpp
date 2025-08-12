class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int i =1;

        while(i<n){
            if(nums[i] < nums[i-1]){
                swap(nums[i],nums[i-1]);
            }
            if(i+1 < n && nums[i] < nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
            else i+=2;
        }
    }
};