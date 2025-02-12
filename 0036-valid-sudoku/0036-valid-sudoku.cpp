class Solution {
private:
bool isValid(int rowstart,int rowend, int colstart, int colend, vector<vector<char>>sudoku){
    vector<bool>visited(10,false);
    for(int i = rowstart; i<rowend; i++){
        for(int j = colstart;j<colend;j++){
            if(sudoku[i][j] !='.'){
                int num = sudoku[i][j]-'0';
                if(visited[num])return false;
                visited[num] = true;
            }
        }
    }
    return true;
}
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check rows
        for(int i = 0; i<9;i++){
            if(!isValid(i,i+1,0,9,board)) return false;
        }
        //check columns
        for(int i = 0; i<9;i++){
            if(!isValid(0,9,i,i+1,board)) return false;
        }
        //check grid
        for(int i = 0; i<3;i++){
            for(int j =0; j<3;j++){
                if(!isValid(i*3, (i+1)*3, j*3, (j+1)*3, board)) return false;
            }
        }
        return true;
    }
};