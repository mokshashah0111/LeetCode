class Solution {
public:
    bool isValid(vector<vector<char>>& maze, int row, int col){
        return row>=0 && row<maze.size() && col>=0 && col<maze[0].size() && maze[row][col] == '.';
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
        queue<tuple<int,int,int>>q;
        vector<vector<bool>>visited(rows, vector<bool>(cols,false));
        int minSteps = INT_MAX;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        q.push({entrance[0],entrance[1],0});
        visited[entrance[0]][entrance[1]] = true;
        while(!q.empty()){
            auto [currRow, currCol,currSteps] = q.front();q.pop();
            if(currSteps !=0 && (currRow == rows-1 || currCol == cols-1 || currRow ==0 || currCol ==0)){
                return currSteps;
            }
            for(int i =0; i<4;i++){
                int nr = currRow + delrow[i];
                int nc = currCol + delcol[i];
                if(isValid(maze, nr,nc) && visited[nr][nc] == false){
                    q.push({nr,nc,currSteps+1});
                    visited[nr][nc] = true;
                }
            }
        }
        return -1;
    }
};