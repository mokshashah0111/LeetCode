class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();

        vector<int>rows(rowsize,0);
        vector<int>cols(colsize,0);

        for(int i = 0; i<rowsize;i++){
            for(int j = 0; j<colsize;j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i =0; i<rowsize;i++){
            for(int j = 0; j<colsize;j++){
                if(rows[i] ==1 || cols[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};