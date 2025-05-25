class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for(int& count: apple){
            total+=count;
        }

        sort(capacity.begin(),capacity.end(),greater<int>());
        int boxes =0;
        int i =0;
        while(total>0){
            total-=capacity[i];
            i++;
            boxes++;
        }
        return boxes;
    }
};