class Solution {
    private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node){
        visited[node] = true;
        for(int i = 0; i<isConnected.size();i++){
            if(isConnected[node][i] == 1 && !visited[i]){    
                visited[i] = true;
                dfs(isConnected, visited, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool>visited(n,false);
        for(int i = 0; i<n;i++){
            if(!visited[i]){
                count+=1;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    }
};