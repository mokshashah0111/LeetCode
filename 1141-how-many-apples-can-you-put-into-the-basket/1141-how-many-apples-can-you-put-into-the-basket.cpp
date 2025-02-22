class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(),weight.end());
        int maxApples = 0;
        int sum = 0;
        for(int i = 0; i<weight.size();i++){
            sum+=weight[i];
            if(sum>5000) return maxApples;
            maxApples++;
        }
        return maxApples;
    }
};