class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;
        for(int i =0;i<nums2.size();i++){
            map[nums2[i]] =i;
        }
        vector<int>result(nums1.size(),-1);
        for(int i =0; i<nums1.size();i++){
            int current = nums1[i];
            int index = map[current];

            while(index<nums2.size()){
                if(nums2[index] > current){
                    result[i] =nums2[index];
                    break;
                }
                index++;
            }
            // if(index==nums2.size()-1) result[i] = -1;
        }
        return result;
    }
};