class Solution {
    private:
    bool isValid(int row,int col,vector<vector<int>>& image){
        int rowSize = image.size();
        int colSize = image[0].size();
        return(row>=0 && row<rowSize && col>=0 && col<colSize);
    }
    void dfs(vector<vector<int>>& image, int row,int col, int color,vector<vector<bool>>& visited){
        if(visited[row][col] || !isValid(row,col,image)) return;
        int Originalcolor = image[row][col];
        image[row][col] = color;
        visited[row][col] = true;
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,-1,0,1};

        for(int i = 0 ;i<4;i++){
            int newRow = row+delrow[i];
            int newCol = col+delcol[i];
            if(isValid(newRow,newCol,image) && image[newRow][newCol] == Originalcolor){
                dfs(image,newRow,newCol,color,visited);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size(),false));
        dfs(image,sr,sc,color,visited);
        return image;
    }
};