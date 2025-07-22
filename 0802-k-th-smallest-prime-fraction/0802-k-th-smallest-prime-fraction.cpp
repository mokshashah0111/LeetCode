class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>>maxHeap;

        for(int i=0; i<arr.size();i++){
            for(int j= i+1; j<arr.size();j++){
                maxHeap.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
                if(maxHeap.size() >k)maxHeap.pop();
            }
        }
        int a = maxHeap.top().second.first;
        int b= maxHeap.top().second.second;
        return {a,b};
    }
};