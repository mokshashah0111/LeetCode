class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        unordered_set<char>visited;
        unordered_map<char,int>position;
        for(int i=0; i<s.size();i++){
            position[s[i]] = i;
        }
        for(int i = 0 ; i<s.size();i++){
            if(visited.find(s[i]) != visited.end()){
                continue;
            }
            while(!st.empty() && s[i] < st.top() && i<position[st.top()]){
                visited.erase(st.top());
                st.pop();
            }
            st.push(s[i]);
            visited.emplace(s[i]);
        }
        string result;
        while(!st.empty()){
            result = st.top()+result;
            st.pop();
        }
        return result;

    }
};