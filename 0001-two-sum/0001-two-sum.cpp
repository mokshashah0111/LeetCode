class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start_ptr = 0;
        int end_ptr = start_ptr;
        vector<int>ans;
        while(start_ptr < nums.size()-1){
            ans = {};
            ans.emplace_back(start_ptr);
            target -= nums[start_ptr];
            for(int i = start_ptr+1;i<nums.size();i++){
                if(target == nums[i]){
                    target-=nums[i];
                    ans.emplace_back(i);
                    break;
                }
            }
            if(target==0) break;
            target+=nums[start_ptr];
            start_ptr++;
        }
        return ans;
    }
};