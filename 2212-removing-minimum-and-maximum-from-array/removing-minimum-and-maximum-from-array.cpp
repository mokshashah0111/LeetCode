class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int size = nums.size();
        if(size==1 || size==2) return size;
        int mini =INT_MAX;
        int maxi = INT_MIN;

        for(int& n: nums){
            mini= min(n, mini);
            maxi = max(n,maxi);
        }

        int start = -1;
        int end = -1;
        for(int i=0; i<size;i++){
            if(nums[i] == mini){
                start =i;
            }
            if(nums[i] == maxi) end =i;
        }
        if(start > end)swap(start,end);
        int ans1 = size-start;
        int ans2 = end+1;
        int ans3 = (size-end)+(start+1);

        return min(ans1, min(ans2,ans3));
    }
};