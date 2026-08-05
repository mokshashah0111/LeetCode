class Solution {
    void dfs(vector<vector<int>>& adj, int k, vector<bool>& visited){
        visited[k] = true;
        for(auto& node: adj[k]){
            if(!visited[node]){
                dfs(adj,node, visited);
            }
        }
    }

    void bfs(vector<vector<int>>& adj, int target, vector<bool>& visited){
        vector<bool>seen(adj.size(),false);
        queue<int>q;
        seen[0] = true;
        q.push(0);

        while(!q.empty()){
            int current = q.front();
            q.pop();

            for(auto& node : adj[current]){
                if(!visited[current] && node == target){
                    visited[target] = false;
                    break;
                }
                q.push(node);
                seen[node] = true;
            }
        }

    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto& methods: invocations){
            adj[methods[0]].emplace_back(methods[1]);
        }
        vector<bool>visited(n,false);
        dfs(adj,k,visited);

        vector<int>ans;

        for(auto& it: invocations){
            int u = it[0];
            int v = it[1];

            if(!visited[u] && visited[v]){
                for(int i =0; i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        for(int i=0; i<n;i++){
            if(!visited[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};