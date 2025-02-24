class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int i = cost.size()-1;
        int mincost = 0;
        while(i >=0){
            mincost = mincost + cost[i] + (i-1>=0 ? cost[i-1]:0);
            i-=3;
        }
        return mincost;
    }
};