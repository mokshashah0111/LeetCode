class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();
        int top = 0;
        int left = 0;
        int bottom = rowsize-1;
        int right = colsize-1;
        vector<int>result;

        while(top<=bottom && left <= right){
            //store the numbers from left to right
            for(int i = left; i<=right;i++){
                result.emplace_back(matrix[top][i]);
            }
            top++;
            //move from top to bottom
            for(int i = top;i <=bottom;i++){
                result.emplace_back(matrix[i][right]);
            }
            right--;
            //move from right to left;
            if(top<=bottom){
                for(int i = right; i>=left;i--){
                    result.emplace_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                //move from bottom to top
                for(int i = bottom; i>=top;i--){
                    result.emplace_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};