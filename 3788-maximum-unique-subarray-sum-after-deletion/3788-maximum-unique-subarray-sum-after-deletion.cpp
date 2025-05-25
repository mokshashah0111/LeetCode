class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int sum=nums[0];
        for(int i=1; i<nums.size();i++){
            if((nums[i]==nums[i-1]) || nums[i]<0) continue;
            else sum+=nums[i];
        }
        return sum;
    }
};