class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool>visited(nums.size(),false);
        int operation = 0;
        int temp =k;
        while(!nums.empty()){
            operation++;
            int x = nums.back();
            nums.pop_back();
            if(x<=k && !visited[x])temp--;
            visited[x]=true;
            if(!temp)break;
        }
        return operation;
    }
};