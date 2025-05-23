class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>prefix(nums.size()+1,0);
        for(int i =1; i<=nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i-1];
        }
        
        vector<int>ans;
        for(int q: queries){
            int index = upper_bound(prefix.begin(),prefix.end(),q)-prefix.begin()-1;
            ans.emplace_back(index);
        }
        return ans;
    }
};