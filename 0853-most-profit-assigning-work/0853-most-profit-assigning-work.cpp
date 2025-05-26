class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>map;
        for(int i =0;i<difficulty.size();i++){
            map.emplace_back(difficulty[i],profit[i]);
        }
        sort(map.begin(),map.end());
        sort(worker.begin(),worker.end());
        int maxProfit = 0;
        int j =0;
        int best =0;
        for(int& work: worker){
            int current = work;
            while(j<map.size() && map[j].first<=current){
                best = max(best, map[j].second);
                j++;
            }
            maxProfit+=best;
        }
        return maxProfit;
    }
};