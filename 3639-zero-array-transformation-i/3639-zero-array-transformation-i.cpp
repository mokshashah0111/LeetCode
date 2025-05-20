class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>difference(nums.size(),0);
        for(auto& query: queries){
            int left = query[0];
            int right = query[1];

            difference[left]++;
            if(right+1< nums.size()) difference[right+1]--;
        }
        int cnt = 0;
        for(int i =0; i<difference.size();i++){
            cnt+=difference[i];
            if(cnt <nums[i]) return false;
        }
        return true;
    }
};