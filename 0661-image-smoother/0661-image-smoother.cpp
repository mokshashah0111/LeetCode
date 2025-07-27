class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();

        int delrow[] = {-1,-1,-1,0,1,1,1,0};
        int delcol[] = {-1,0,1,1,1,0,-1,-1};
        vector<vector<int>>result = img;
        for(int i = 0;i<rows;i++){
            for(int j =0;j<cols;j++){
                int sum = img[i][j];
                int count =1;

                for(int x =0;x<8;x++){
                    int nr = i+delrow[x];
                    int nc = j+ delcol[x];

                    if(nr>=0 && nr<rows && nc>=0 && nc<cols){
                        sum+= img[nr][nc];
                        count++;
                    }
                }
                result[i][j] = sum /count;
            }
        }
        return result;
    }
};