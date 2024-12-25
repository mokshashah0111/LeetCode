class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());

        int ptr_g = 0;
        int ptr_s = 0;

        while(ptr_g <g.size() && ptr_s <s.size()){
            if(g[ptr_g] <= s[ptr_s]){
                ptr_g++;
                ptr_s++;
            }
            else ptr_s++;
        }
        return ptr_g;
    }
};