class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        for(auto& it: prerequisites){
            adj[it[0]].emplace_back(it[1]);
        }
        vector<bool>result;
        vector<bool>visited(numCourses,false);

        for(auto& qr: queries){
            int current = qr[0];
            int target = qr[1];
            queue<int>q;
            // q.clear();
            fill(visited.begin(),visited.end(),false);
            q.emplace(current);

            visited[current] = true;
            bool found = false;
            while(!q.empty()){
                int top = q.front();q.pop();
                if(top == target){
                    found = true;
                    break;
                }
                for(auto it: adj[top]){
                    if(!visited[it]){
                        q.emplace(it);
                        visited[it] = true;
                    }
                }
            }
            result.emplace_back(found);
        }
        return result;
    }
};