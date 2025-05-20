class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int score =0;
        int maximum = -1;
        for(int num: nums){
            maximum = max(num,maximum);
        }
        while(k--){
            score+=maximum;
            maximum+=1;
        }
        return score;
    }
};