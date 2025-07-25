class Solution {
    bool isValid(int row, int col, vector<vector<char>>& grid){
        return row>=0 && row<grid.size() && col>=0 && col<grid[0].size();
    }
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int kills = 0;
        queue<pair<int,int>>q;
        // q.emplace(0,0);
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        
        for(int i =0; i<m;i++){
            for(int j =0; j<n;j++){
                if(grid[i][j] == '0'){
                    q.emplace(i,j);
                }
            }
        }

        while(!q.empty()){
            auto[currRow, currCol] = q.front();
            q.pop();
            int nr = currRow;
            int temp = 0;
            while(nr >=0){
                if(grid[nr][currCol] == 'W')break;
                temp+=  grid[nr][currCol] == 'E';
                nr--;
            }
            nr = currRow;
            while(nr < grid.size()){
                if(grid[nr][currCol] == 'W') break;
                temp+= grid[nr][currCol]=='E';
                nr++;
            }
            int nc = currCol;
            while(nc >=0){
                if(grid[currRow][nc] == 'W') break;
                temp+= grid[currRow][nc] == 'E';
                nc--;
            }
            nc = currCol;
            while(nc < grid[0].size()){
                if(grid[currRow][nc] == 'W') break;
                temp+= grid[currRow][nc] == 'E';
                nc++;
            }
            kills = max(kills,temp);
        }
        return kills;
    }
};