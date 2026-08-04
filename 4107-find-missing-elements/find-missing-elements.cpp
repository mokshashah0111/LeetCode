class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi= INT_MIN;

        for(int element: nums){
            mini = min(mini,element);
            maxi = max(maxi, element);
        }

        vector<bool>freq(maxi+1,false);
        for(int element: nums){
            freq[element] = true;
        }
        vector<int>ans;
        for(int i=mini; i<=maxi;i++){
            if(freq[i] == false){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};