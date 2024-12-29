class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>result;
        if(nums.size()==0){
            result.push_back(vector<int>{lower,upper});
            return result;
        }
        if(nums[0] != lower){
            result.emplace_back(vector<int>{lower,nums[0]-1});
        }

        for(int i=0; i<nums.size()-1;i++){
            if(nums[i+1] - nums[i] != 1){
                result.emplace_back(vector<int>{nums[i]+1, nums[i+1]-1});
            }
        }
        if(nums[nums.size()-1] != upper){
            result.emplace_back(vector<int>{nums[nums.size()-1]+1, upper});
        }
        return result;
    }
};