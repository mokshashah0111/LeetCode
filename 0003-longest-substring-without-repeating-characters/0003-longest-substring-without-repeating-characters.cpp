class Solution {
public:
    int lengthOfLongestSubstring(string s) {    
        int maxLength = 0;
        unordered_map<char,int>mpp;

        for(int j=0, i=0; j<int(s.length());j++){
            if(mpp[s[j]] >0){
                i = max(i,mpp[s[j]]);
            }
            maxLength= max(maxLength,j-i+1);
            mpp[s[j]] = j+1;
        }
        return  maxLength;
    }
};