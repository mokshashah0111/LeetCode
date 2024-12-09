class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size(),-1);
        for(int i = 0;i<nums.size();i++){
            int number = nums[i];
            for(int x = 0; x<=number-1 ;x++){
                if((x |(x+1)) == nums[i]){
                    ans[i] = x;
                    break;
                }
            }
        }
        return ans;
    }
};