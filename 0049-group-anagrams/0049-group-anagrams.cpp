class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string str: strs){
            string anagram = str;
            sort(str.begin(),str.end());
            mp[str].emplace_back(anagram);
        }
        vector<vector<string>>result;
        for(auto it: mp){
            // if(it.second.size()>=2){
            result.emplace_back(it.second);
            // }
        }
        return result;
    }
};