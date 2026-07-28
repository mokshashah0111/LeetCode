class Solution {
public:
    string smallestPalindrome(string s) {
        int size = s.size();
        map<char,int>freq;

        for(char c: s){
            freq[c]++;
        }
        int start = 0;
        int end = size-1;

        for(auto element : freq){
            char c = element.first;
            int count =  element.second;
            cout<< c<<','<<count<<endl;
            if(count %2 !=0 && size%2 !=0){
                s[size/2] = c;
                count--;
            }
            while(count){
                s[start] = c;
                s[end] =c;
                start++;
                end--;
                count-=2;
            }
        }
        return s;
    }
};