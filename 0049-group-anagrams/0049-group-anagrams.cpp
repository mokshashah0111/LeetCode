class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>result;
        for(auto it: strs){
            string str = it;
            sort(it.begin(),it.end());
            mpp[it].emplace_back(str);
        }
        for(auto it : mpp){
            result.emplace_back(it.second);
        }
        return result;
    }
};