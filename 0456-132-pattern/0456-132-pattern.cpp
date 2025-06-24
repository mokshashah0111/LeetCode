class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>>st;
        int currMin = nums[0];
        st.push({nums[0],currMin});

        for(int i =1;i<nums.size();i++){
            while(!st.empty() && st.top().first <= nums[i])st.pop();
            if(!st.empty() && st.top().second < nums[i]) return true;
            currMin= min(currMin,nums[i]);
            st.push({nums[i],currMin});
        }
        return false;
    }
};