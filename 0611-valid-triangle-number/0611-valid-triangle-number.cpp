class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int triplets = 0;
        for(int i = 0; i<nums.size();i++){
            for(int j = i+1; j<nums.size();j++){
                int left = j+1;
                int right = nums.size()-1;
                int k=j;
                while(left <= right){
                    int mid = left+(right-left)/2;
                    if(nums[i] + nums[j] > nums[mid]){
                        k=mid;
                        left=mid+1;
                    }
                    else right = mid-1;
                }
                triplets +=k-j;
            }
        }
        return triplets;
    }
};