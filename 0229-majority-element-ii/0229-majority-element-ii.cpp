class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int vote1 =0;
        int vote2 =0;
        int max1 =0;
        int max2 = 0;

        for(int& num: nums){//2..1..1..3
            if(num==max1) vote1++;
            else if(num == max2) vote2++;
            else if(vote1 ==0)max1 = num,vote1++;
            else if(vote2 ==0) max2 = num,vote2++;
            else vote1--,vote2--;    
        }
        vote1 =0,vote2 =0;
        for(int& num: nums){
            if(num== max1)vote1++;
            else if(num==max2) vote2++;
        }
        vector<int>result;
        if(vote1>nums.size()/3)result.emplace_back(max1);
        if(vote2>nums.size()/3)result.emplace_back(max2);
        return result;
    }
};