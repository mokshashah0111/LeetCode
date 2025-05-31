class Solution {
    private:
    bool isValid(char num, int row,int col, vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][col] == num) return false;
            if(board[row][i] == num) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == num) return false;
        }
        return true;
    }
    bool solveHelper(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col =0;col<9;col++){
                if(board[row][col] =='.'){
                    for(char num='1';num<='9';num++){
                        if(isValid(num,row,col,board)){
                            board[row][col] = num;
                            if(solveHelper(board)) return true;
                            board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveHelper(board);
    }
};