class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while(columnNumber){
            columnNumber--;
            int col = columnNumber%26;
            result+= (col+'A');
            columnNumber/=26;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};