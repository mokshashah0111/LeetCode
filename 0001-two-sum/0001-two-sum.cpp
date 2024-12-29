class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int>mp;
        vector<int>ans;
        for(int i= 0; i<nums.size();i++){
            int a = nums[i];
            int rem = target -a;
           
            if(mp.find(rem) != mp.end()){
                ans.emplace_back(mp[rem]);
                ans.emplace_back(i);
                break;
            }
            mp[a] =i;
        }
        return ans;
    }
};