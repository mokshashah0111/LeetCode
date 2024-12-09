class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i<nums.size();i++){
            int temp =i;
            int indexSum = 0;
            while(temp){
                indexSum += temp%2;
                temp /=2;
            }
            if(indexSum == k)sum+=nums[i];
        }
        return sum;
    }
};