class Solution {
private:
string expand(int left, int right, string s){

    while(left>=0 && right<s.length() && s[left] == s[right]){
        left--;
        right++;
    }
    return s.substr(left+1,right-left-1);
}
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i<s.size();i++){
            string odd= expand(i,i,s);
            if(odd.size() > ans.size()) ans = odd;
            string even = expand(i,i+1,s);
            if(even.size() > ans.size()) ans= even;
        }
        return ans;
    }
};