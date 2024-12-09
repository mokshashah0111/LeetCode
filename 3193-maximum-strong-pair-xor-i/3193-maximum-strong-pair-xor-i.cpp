class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int result = -1;
        for(int firstNum: nums){
            for(int secNum: nums){
                if(abs(firstNum-secNum) <= min(firstNum, secNum)){
                    if(result!=-1){
                        result = max(result,firstNum^secNum);
                    }
                    else result = firstNum^secNum;
                }
            }
        }
        return result;
    }
};