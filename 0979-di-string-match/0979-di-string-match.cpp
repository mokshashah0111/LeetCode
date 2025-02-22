class Solution {
public:
    vector<int> diStringMatch(string s) {
        int size = s.size();
        int i =0;
        int j = size;
        vector<int>result;
        for(int x = 0;x<size;x++){
            if(s[x] == 'I'){
                result.emplace_back(i);
                i++;
            }
            else if(s[x] == 'D'){
                result.emplace_back(j);
                j--;
            }
        }
        result.emplace_back(i);
        return result;
    }
};