class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int j =0;
        int index = nums.size()-1;
        int k = index/2 +1;

        while(index>=0){
            if(index%2 ==0){
                nums[index] = temp[j];
                j++;
            }
            else{
                nums[index] = temp[k];
                k++;
            }
            index--;
        }

    }
};