class Solution {
public:
    string smallestPalindrome(string s) {
        int size = s.size();
        vector<int>freq(26,0);
        for(char c: s){
            freq[c-97]++;
        }
        int start =0;
        int end = size-1;
        
        for(int i =0; i<26;i++){
            int count = freq[i];
            if(count==0) continue;
            if(count%2 !=0 ){
                s[size/2]= static_cast<char>(i+97);
                count--;
            }
            while(count){
                s[start] = static_cast<char>(i+97);
                s[end]= static_cast<char>(i+97);
                start++;
                end--;
                count-=2;
            }
        }
        return s;
    }
};