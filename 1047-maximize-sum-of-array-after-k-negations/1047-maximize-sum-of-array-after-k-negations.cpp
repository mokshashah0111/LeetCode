class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>minHeap;
        int sum =0;
    
        for(int num: nums){
            minHeap.push(num);
            sum+=num;
        }
        while(k>0){
            int number = minHeap.top();
            minHeap.pop();
            sum-= number;
            number=number*(-1);
            sum+=number;
            minHeap.push(number);
            k--;
        }
        return sum;
    }
};