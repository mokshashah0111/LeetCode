class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1]<=b[1];
        });
        int maxUnits = 0;
        int rem = truckSize;
        for(int i = boxTypes.size()-1;i>=0;i--){
            if(rem >= boxTypes[i][0]){
                rem -= boxTypes[i][0];
                maxUnits+= boxTypes[i][1] * boxTypes[i][0];
            }
            else if(rem<boxTypes[i][0]){
                maxUnits += rem*boxTypes[i][1];
                rem =0;
            }
            if(rem ==0) return maxUnits;
        }
        return maxUnits;
    }
};