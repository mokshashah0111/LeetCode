class Solution {
private:
    void transpose(vector<vector<int>>& matrix){
        for(int i = 0; i<matrix.size()-1;i++){
            for(int j = i; j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]); 
            }
        }
    }
public:

    void rotate(vector<vector<int>>& matrix) {
        int matrixSize = matrix.size();
        transpose(matrix);
        for(int i = 0; i<matrixSize;i++){
            std::reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};