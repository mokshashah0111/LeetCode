class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char& c: num){
            while(!st.empty() && st.top() > c && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(!st.empty() && k>0){
            st.pop();k--;
        }
        string result;
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        int pos = result.find_first_not_of("0");
        return pos== string::npos ? "0" : result.substr(pos);
    }
};