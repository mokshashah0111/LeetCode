class Solution {
    /*
    0---1,2,3
    1---0,4
    2---0
    3---0
    4---1
    visited = false,false,false,false,false
    bool dfs(adj, visited, node,parent){
        visited[node]= true;
        for(neightbors : adj[node]){
            if(!visited[neightbors]){
                dfs(adj,visited,neightbors,node) return true;
            }
           else if(neightbors != node) return true; -----cycle detected
        }
        return false;
    }
    */

    private:
    bool isVisited(vector<vector<int>>& adj, vector<bool>& visited, int node,int parent){
        visited[node] = true;
        for(auto it: adj[node]){
            if(!visited[it]){
                if(isVisited(adj,visited,it,node)) return true;
            }
            else if(it != parent) return true; //cycle detected
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it: edges){
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }
        vector<bool>visited(n,false);
        if(isVisited(adj,visited,0,-1)) return false;
        for(bool v: visited){
            if(!v) return false;
        }
        return true; 
    }
};