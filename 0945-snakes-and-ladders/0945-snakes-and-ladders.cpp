class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n  = board.size();
        vector<int>minRolls(n*n+1, -1);
        queue<int>q;

        minRolls[1] =0;
        q.push(1);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(int i = 1;i<=6;i++){
                int nextIndex = curr+i;
                int row = (nextIndex-1)/n;
                int col = (nextIndex-1)%n;

                int num= board[n-row-1][row%2 ? n-col-1: col];
                int nextPos = num >0 ? num : nextIndex;

                if(nextPos == n*n) return minRolls[curr]+1;
                if(minRolls[nextPos]==-1){
                    minRolls[nextPos] = minRolls[curr]+1;
                    q.push(nextPos);
                }
            }
        }
        return -1;
    }
};