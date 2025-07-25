class Solution {
    int lcp(string s1, string s2, string s3){
        int len =0;
        int i =0; int j =0; int k=0;

        while(i<s1.size() && j<s2.size() && k<s3.size()){
            if(s1[i] == s2[j] && s2[j] == s3[k]){
                len++;
                i++;j++;k++;
            } 
            else return len;
        }
        return len;
    }
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int m = s1.size();
        int n= s2.size();
        int o = s3.size();
        int common = lcp(s1,s2,s3);
        if(common == 0) return -1;
        return (m-common) + (n-common) + (o-common);
    }
};