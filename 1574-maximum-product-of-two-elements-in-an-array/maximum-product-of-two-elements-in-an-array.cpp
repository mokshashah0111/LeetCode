class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;

        for(int element: nums){
            if(max1 < element){
                max2 = max1;
                max1 = element;
            }
            else if(max2==INT_MIN || (element<=max1 && element>max2)){
                max2 = element;
            }
        }
        return (max1-1)*(max2-1);
    }
};