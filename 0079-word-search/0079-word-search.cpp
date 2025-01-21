class Solution {

    private:
    bool isValid(int row,int col,vector<vector<char>>& board){
        return row>=0 && row<board.size() && col>=0 && col<board[0].size();
    }
    bool helper(vector<vector<char>>& board, string word, int row, int col, int index, int delrow[],int delcol[],vector<vector<bool>>& visited){
        if(index == word.size()) return true;
        if(!isValid(row,col,board) || visited[row][col] || board[row][col] != word[index]) return false;
        visited[row][col] = true;
        for(int i = 0;i<4;i++){
            int newRow = row+delrow[i];
            int newCol = col+delcol[i];
            if(helper(board,word,newRow,newCol,index+1,delrow,delcol,visited)) return true;
        }
        visited[row][col] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i = 0; i<board.size();i++){
            for(int j = 0; j<board[0].size();j++){
                if(helper(board,word,i,j,0,delrow,delcol,visited)) return true;
            }
        }
        return false;
    }
};