class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string result="";
        int count=0;
        for(int i =0; i<s.size();i++){
            if(s[i]=='1') count++;
        }
        for(int i=0; i<count-1;i++){
            result+='1';
        }
        for(int i =0; i<s.size()-count;i++){
            result+='0';
        }
        result+='1';
        return result;
    }
};