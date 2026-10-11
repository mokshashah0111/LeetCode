class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>prefixMap;
        prefixMap[0] = -1;
        int currSum = 0;
        int maxSum =0;

        for(int i =0;i<nums.size();i++){
            currSum += (nums[i] ==0) ? -1: 1;
            if(prefixMap.count(currSum)){
                maxSum = max(maxSum, i-prefixMap[currSum]);
            }
            else{
                prefixMap[currSum]= i;
            }
        }
        return maxSum;
    }
};