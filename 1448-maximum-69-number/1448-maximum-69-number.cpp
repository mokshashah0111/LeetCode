class Solution {
public:
    int maximum69Number (int num) {
        vector<int>nums;
        int current = num;
        while(current!=0){
            nums.emplace_back(current%10);
            current /=10;
        }
        reverse(nums.begin(),nums.end());
        for(int i =0; i<nums.size();i++){
            if(nums[i] == 6){
                nums[i] =9;
                break;
            } 
        }
        int newNumber =0;
        for(int i = 0; i<nums.size();i++){
            newNumber= (newNumber*10)+nums[i];
            // newNumber *= 10;
        }
        return newNumber;
    }
};