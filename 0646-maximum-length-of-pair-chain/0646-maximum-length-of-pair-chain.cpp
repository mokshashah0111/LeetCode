class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int length =0;
        int currentMax = INT_MIN;
        sort(pairs.begin(),pairs.end(),[](vector<int>&A, vector<int>& B){return A[1] < B[1];});
        for(int i=0; i<pairs.size();i++){
            if(pairs[i][0] > currentMax){
                length++;
                currentMax=pairs[i][1];
            }
        }
        return length;
    }
};