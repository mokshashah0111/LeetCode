class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.rbegin(),tasks.rend());
        sort(processorTime.begin(),processorTime.end());
        int time = 0;
        int taskIndex = 0;
        int taskDivision = tasks.size()/processorTime.size();
        for(int i = 0; i<processorTime.size();i++){
            time = max(time, processorTime[i] + tasks[taskIndex]);
            taskIndex += taskDivision;
        }
        return time;
    }
};