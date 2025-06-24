class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int,priority_queue<int>>map;
        for(auto it: items){
            int ID = it[0];
            int score = it[1];

            map[ID].push(score);
        }

        vector<vector<int>>result;

        for (auto& [id, pq] : map) {
            int sum = 0;
            for (int i = 0; i < 5 && !pq.empty(); ++i) {
                sum += pq.top();
                pq.pop();
            }
            result.push_back({id, sum / 5});
        }
        sort(result.begin(),result.end());
        return result;
    }
};