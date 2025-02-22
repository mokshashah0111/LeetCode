/*
sorting = 3,4,8,9,10

*/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int>result;
        sort(nums.begin(),nums.end());
        int sum =0;
        for(int num: nums){
            sum+=num;
        }
        int partial =0;
        int i = nums.size()-1;
        while(sum-partial >= partial){
            partial+= nums[i];
            result.emplace_back(nums[i]);
            i--;
        }
        return result;
    }
};