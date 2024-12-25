class Solution {
public:
    int GCDhelper(int a, int b){
        int rem = a%b;
        if(rem==0) return b;

        a = b;
        b= rem;
        return GCDhelper(a,b);
    }
    int findGCD(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        return GCDhelper(nums[0],nums[nums.size()-1]);
    }
};