class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        for(int i=0;i<min(s.size(),t.size());i++){
            if(s[i] != t[i]){
                if(s.size()==t.size()){
                    return s.substr(i+1)==t.substr(i+1);
                }
                else if(s.size()>t.size()){
                    return s.substr(i+1) == t.substr(i);
                }
                else{
                    return s.substr(i) == t.substr(i+1);
                }
            }
        }
        return s.size() > t.size() ? s.size()-t.size()==1 : t.size()-s.size()==1;
    }
};