class Solution {
    pair<int,int> first_greater(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        pair<int,int> result= {0,nums[0]};
        while(low<=high){
            int mid = low+(high-low)/2;

            if(nums[mid] > target){
                result = {mid,nums[mid]};
                high = mid-1;
            }
            else low = mid+1;
        }
        return result;
    }
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        vector<int>result(nums2.size());
        for(int i =0;i<nums2.size();i++){
            auto ans = first_greater(nums1 , nums2[i]);
            int index = ans.first;
            int num = ans.second;
            nums1.erase(nums1.begin()+index);
            result[i] = num;
        }
        return result;
    }
};