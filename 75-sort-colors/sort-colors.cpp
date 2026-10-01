class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
        divide the array into 4 subarrays- bottom, equal, unclassified, greater
        bottom -> 0s
        equal -> 1s
        unclassified-> unsorted array
        greater -> 2s
        */

        int size = nums.size();
        int bottom = 0;
        int equal =0;
        int greater = size-1;
        
        // nums = [2,0,2,1,1,0]
        while(equal <= greater){//0...1
            //nums[equal]-> 2
            if(nums[equal]==0){
                swap(nums[equal], nums[bottom]);
                equal++;
                bottom++;//(1,0)
                //bottom->0.....1
            }
            else if(nums[equal] ==1)equal++;
            else{
                swap(nums[equal], nums[greater]);
                greater--;//(2,5)
                //greater->5....4
            }
            //final -> 0,0,2,1,1,2
        }
    }
};