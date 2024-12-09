class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count=0;
        for(int number:nums){
            if(((number&1) & 1) == 0) count++;
        }
        return count>=2;
    }
};