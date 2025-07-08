class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>>isReachable(numCourses,vector<bool>(numCourses,false));
        vector<vector<int>>adj(numCourses);
        vector<int>inDegrees(numCourses);
        for(auto it: prerequisites){
            adj[it[0]].emplace_back(it[1]);
            inDegrees[it[1]]++;
        }
        // for(int i =0; i<numCourses;i++){
        //     for(int j: adj[i]){
        //         inDegrees[j]++;
        //     }
        // }
        
        queue<int>q;
        for(int i =0; i<numCourses;i++){
            if(inDegrees[i] ==0)q.emplace(i);
        }

        while(!q.empty()){
            auto current = q.front(); q.pop();
            for(auto it: adj[current]){
                isReachable[current][it] = true;
                for(int i =0;i<numCourses;i++){
                   if(isReachable[i][current]){
                        isReachable[i][it]= true;
                   }
                }
                inDegrees[it]--;
                if(inDegrees[it] ==0)q.emplace(it);
            }
        }
        vector<bool>result;
        for(auto it: queries){
            result.emplace_back(isReachable[it[0]][it[1]]);
        }
        return result;
    }
};