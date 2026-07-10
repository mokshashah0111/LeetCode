class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxLen  =0;
        while(!st.empty()){
            int a = *begin(st);
            st.erase(a);

            int lower = a-1;
            while(st.count(lower)){
                st.erase(lower);
                lower--;
            }
            int upper = a+1;
            while(st.count(upper)){
                st.erase(upper);
                upper++;
            }

            maxLen = max(maxLen,upper-lower-1);
        }
        return maxLen;
    }
};