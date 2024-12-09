class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int genNum = 0;
        for(int i =0; i<32 ;i++){
            int sum = 0;
            for(int number: nums){
                sum+= ((number>>i) & 1);
            }
            if(sum>=k){
                genNum |= 1<<i;
            }
            // if(pow(2, i)>k)break;
        }
        return genNum;
    }
};