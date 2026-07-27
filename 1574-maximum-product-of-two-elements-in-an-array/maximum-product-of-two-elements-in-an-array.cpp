class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>product;
        int maxProduct = INT_MIN;
        for(int i=0; i<nums.size()-1;i++){
            for(int j=1;j<nums.size();j++){
                if(i==j) continue;
                // product.push((nums[i]-1)* (nums[j]-1));
                maxProduct = max(maxProduct, (nums[i]-1)*(nums[j]-1));
            }
        }
        return maxProduct;
        // return product.top();
    }
};