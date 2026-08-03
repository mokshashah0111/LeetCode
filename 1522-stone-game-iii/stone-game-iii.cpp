class Solution {
    int final(vector<int>& stoneValue, int index, vector<int>& memo){
        if(index >= stoneValue.size()) return 0;
        if(memo[index] != INT_MAX) return memo[index];

        int m1 = stoneValue[index] - final(stoneValue,index+1, memo);
        int m2 = stoneValue[index] + (index+1 <stoneValue.size() ? stoneValue[index+1] : 0) - final(stoneValue,index+2,memo);
        int m3 = stoneValue[index] + (index+1 <stoneValue.size() ? stoneValue[index+1] : 0) + (index+2< stoneValue.size() ? stoneValue[index+2] : 0) - final(stoneValue,index+3, memo);

        return memo[index] = max(m1, max(m2,m3));
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int rows = stoneValue.size();
        vector<int>memo(rows,INT_MAX);
        int score = final(stoneValue,0,memo);
         
        return score > 0 ? "Alice" : (score==0 ? "Tie" : "Bob");
    }
};