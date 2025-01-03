class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count  =0;
        int max = 0;

        for(int number: nums){
            if(number ==1){
                count++;
                max = std::max(count,max);
            }
            else{
                count = 0;
            }
        }
        return  max;
    }
};