class Solution {
    struct subarray{
        int start;
        int end;
    };
public:
    string minWindow(string s, string t) {
        subarray result = {-1,-1};
        unordered_map<char,int>mp;
        int remaining = t.size();
        for(const char c: t){
            mp[c]++;
        }
        for(int left =0, right= 0; right<s.size();right++){
            if(mp.find(s[right]) != mp.end()){
                if(--mp[s[right]] >=0)remaining--;
            }

            while(remaining == 0){
                if((result.start == -1 && result.end==-1) || right -left < result.end-result.start){
                    result = {left,right};
                }

                if(mp.find(s[left])!= mp.end()){
                    if(++mp[s[left]]>0)remaining++;
                }
                left++;
            }
        }
        return result.start == -1 ? "" : s.substr(result.start ,result.end-result.start+1);
    }
};