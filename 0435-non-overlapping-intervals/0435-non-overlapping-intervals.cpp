class Solution {
    /*
    if lastvisit = INT_MIN--> lastvisit = interval[1]

    */
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(), [](const vector<int>A, const vector<int>B) {return A[1]<B[1];});
        int visits= 0;
        int lastVisit = intervals[0][1];
        for(int i = 1; i<intervals.size();i++){
            if(intervals[i][0] < lastVisit) visits++;
            else lastVisit= intervals[i][1];
        }
        return visits;
    }
};