class Solution {
    private:
    struct building{
        int id, height;
    };
public:
    vector<int> findBuildings(vector<int>& heights) {
        int id =0;
        stack<building>st;
        vector<int>result;

        for(int& num: heights){
            while(!st.empty() && st.top().height <= num) st.pop();
            st.emplace(building{id++,num});
        } 

        while(!st.empty()){
            result.emplace_back(st.top().id);
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};